
//使用微信code或者access_token进行登录
gate.loginCode = function (msg, session, next) {
    var code = msg.code;
    var token = msg.token;
    var appid = msg.appid;
    if (!appid || (!code && !token)) {
        next(null, { code: Code.INVALIDPARAM });
        return;
    }
    if (utils.appConfig(appid) == null || wechat[appid] == null) {
        next(null, { code: Code.GATE.FA_USE_INVALID_APPID });
        return;
    }
    var self = this;
    var wcinfo = wechat[appid];    // 这是根据传入appid获取公众号账户密钥
    var data;
    if (!!code) {   //第一次登录
        getAccessToken(wcinfo.appId, wcinfo.appSecret, code, function (res) {
            if (res.code == Code.OK) {  //获取到access_token
                //保存token数据
                data = {  //缓存结构
                    accessToken: res.data.access_token,
                    refreshToken: res.data.refresh_token,
                    accessTime: Date.now(),
                    refreshTime: Date.now(),
                    accessExpire: res.data.expires_in,
                    openId: res.data.openid
                };
                self.getUserLogin(msg, session, next, data);
                return;
            }
            next(null, res);    //获取token失败
        });
    }
    else {  //后续登录
        userDao.loadRedisWechat(token, function (err, res) {
            if (!err && !!res) {    //用户被缓存
                var data = res;
                if (!!data.accessToken && data.accessToken != '' && data.accessTime != 0) {
                    var nowtime = Date.now();
                    if (nowtime+600000 < data.accessTime + data.accessExpire*1000) {    //token未超时
                        self.getUserLogin(msg, session, next, data);
                        return;
                    }
                    if (nowtime < data.refreshTime + (30-1)*24*3600000) {  //超时可刷新
                        refreshToken(wcinfo.appId, data.refreshToken, function (res) {
                            if (res.code == Code.OK) {  //刷新成功
                                data.accessToken = res.data.access_token;
                                data.refreshToken = res.data.refresh_token;
                                data.accessTime = Date.now();
                                data.accessExpire = res.data.expires_in;
                                data.openId = res.data.openid;
                                self.getUserLogin(msg, session, next, data);
                                return;
                            }
                            next(null, res);    //刷新token失败
                        });
                        return;
                    }
                }
            }
            next(null, {code: Code.FAIL, error: -1});    //无缓存，可以服务器重启过
        });
    }
};

//获取微信用户信息并登录
gate.getUserLogin = function (msg, session, next, data) {
    var self = this;
    getUserInfo(data.accessToken, data.openId, function (res) {
        if (res.code == Code.OK) {  //获取到用户信息
            //缓存用户微信信息
            data.nickname = res.data.nickname;
            data.gender = res.data.sex;
            data.headurl = res.data.headimgurl;
            data.province = res.data.province;
            data.city = res.data.city;
            data.country = res.data.country;
            data.unionId = res.data.unionid;
            userDao.saveRedisWechat(data);
            //进入原微信登录
            msg.openId = data.openId;
            msg.unionId = data.unionId;
            msg.accessToken = data.accessToken;
            msg.userInfo = {
                nickname: data.nickname,
                gender: data.gender,
                headurl: data.headurl
            };
            console.log("userloginmsg:" + JSON.stringify(msg));
            self.loginWechat(msg, session, next);
            return;
        }
        next(null, res);    //获取用户信息失败
    });
};


gate.loginWechat = function (msg, session, next) {
    var openId = msg.openId;
    var unionId = msg.unionId;
    var cid = 1;
    var appid = msg.appid || 1;
    if (!openId) {
        next(null, { code: Code.INVALIDPARAM });
        return;
    }
    if (utils.appConfig(appid) == null) {
        next(null, { code: Code.GATE.FA_USE_INVALID_APPID });
        return;
    }
    var self = this;
    userDao.loginChannel(openId, appid, cid, unionId, function (err, pid, isNew) {
        if (!!err) {
            next(null, err);
            return;
        }
        logger.info('wechat user ' + openId + ' : ' + unionId + ' login!');
        dispatcher.dispatch(pid, function (err, res) {
            if (!!err) {
                logger.error('wechat login failed '+err);
                next(null, { code: Code.FAIL});
                return;
            }
            logger.info('dispatch pid '+pid+' to connector '+res.id);
            next(null, { code: Code.OK, token: Token.create(pid, Date.now(), self.secret, appid), uid: pid, isNew: isNew,
                    host: res.clientHost, port: res.clientPort, accessToken: msg.accessToken || '', userinfo: msg.userInfo || ''});
        });
    });
};

//微信工具函数
//根据微信code获取access_token
var getAccessToken = function (appId, secret, code, cb) {
    var data = {
        appid: appId,
        secret: secret,
        code: code,
        grant_type: 'authorization_code'
    };
    var content = querystring.stringify(data);
    var options = {
        hostname: 'api.weixin.qq.com',
        port: 443,
        path: '/sns/oauth2/access_token?' + content,
        method: 'GET'
    };
    var req = https.request(options, function (res) {
        res.setEncoding('utf8');
        res.on('data', function (body) {
            var tokenData = JSON.parse(body.toString());
            if (!!tokenData.errcode){
                logger.error('#### get access token failed ' + tokenData.errcode);
                cb({ code: Code.FAIL, error: tokenData.errcode });
                return;
            }
            logger.info('#### get access Token ' + JSON.stringify(tokenData));
            cb({ code: Code.OK, data: tokenData});
        });
    });
    req.on('error', function (e) {
        cb({code: Code.FAIL, error: -1});
    });
    req.end();
};

// 刷新access_token，使用时间延长
var refreshToken = function (appId, refresh_token, cb) {
    var data = {
        appid: appId,
        refresh_token: refresh_token,
        grant_type: 'refresh_token'
    };
    var content = querystring.stringify(data);
    var options = {
        hostname: 'api.weixin.qq.com',
        port: 443,
        path: '/sns/oauth2/refresh_token?' + content,
        method: 'get'
    };
    var req = https.request(options, function (res) {
        res.setEncoding('utf8');
        res.on('data', function (body) {
            var tokenData = JSON.parse(body.toString());
            if (!!tokenData.errcode){
                logger.error('#### refresh token failed ' + tokenData.errcode);
                cb({ code: Code.FAIL, error: tokenData.errcode });
                return;
            }
            cb({ code: Code.OK, data: tokenData});
        });
    });
    req.on('error', function (e) {
        cb({code: Code.FAIL, error: -1});
    });
    req.end();
};

//根据access_token获取用户信息
var getUserInfo = function (access_token, openid, cb) {
    var data = {
        access_token: access_token,
        openid: openid,
        lang: 'zh_CN'
    };
    var content = querystring.stringify(data);
    var options = {
        hostname: 'api.weixin.qq.com',
        port: 443,
        path: '/sns/userinfo?' + content,
        method: 'get'
    };
    var req = https.request(options, function (res) {
        res.setEncoding('utf8');
        res.on('data', function (body) {
            var tokenData = JSON.parse(body.toString());
            if (!!tokenData.errcode){
                logger.error('#### get userinfo failed ' + tokenData.errcode);
                cb({ code: Code.FAIL, error: tokenData.errcode });
                return;
            }
            logger.info('#### get userinfo ' + JSON.stringify(tokenData));
            if (tokenData.unionid == '' || !tokenData.unionid){
                var noUnionid = '40029';
                logger.error('#### get userinfo failed ' + noUnionid);
                cb({ code: Code.FAIL, error: noUnionid });
                return;
            }
            cb({ code: Code.OK, data: tokenData});
        });
    });
    req.on('error', function (e) {
        cb({code: Code.FAIL, error: -1});
    });
    req.end();
};
