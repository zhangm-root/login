

#include "stdafx.h"
/*
	title: 杭电2000，三种c, c++, c++ + sort
*/
/*
#include <stdio.h>
int main()
{
	char a, b, c, x;
	while (scanf("%c%c%c", &a, &b, &c) != EOF)
	{
		getchar();
		if (a>b)
		{
			x = a; a = b; b = x;
		}
		if (a>c)
		{
			x = c; c = a; a = x;
		}
		if (b > c)
		{
			x = b; b = c; c = x;
		}
		printf("%c %c %c\n", a, b, c);
	}
	return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
int main() {
	char str[4];
	while (scanf("%s", str) != EOF) {
		sort(str, str + 3);
		for (int i = 0; i<3; i++) {
			if (i == 2)
				printf("%c\n", str[i]);
			if (i<2)
				printf("%c ", str[i]);
		}
	}
	return 0;
}
*/

/*
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	char arr[3];
	while (cin >>arr) {
		sort(arr, arr+3);
		for (int i = 0; i<3; i++) {
			if (i == 2)
				cout << arr[i] << endl;
			if (i < 2)
				cout << arr[i] <<' ';
		}
	}
	return 0;
}
*/

/*
	title: 杭电2001 两种: c, c++
*/
/*
#include <stdio.h>
#include "Math.h"
int main() {
	double a, b, c, d, x;
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != EOF) {
		x = sqrt((a - c)*(a - c) + (b - d)*(b - d));
		printf("%.2lf\n", x);
	}
	return 0;
}


#include <iostream>
#include "Math.h"
using namespace std;
int main() {
	double x, y, x1, y1, dis;
	while (cin >> x >> y >> x1 >> y1) {
		dis = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
		cout.precision(2);
		cout << dis << endl;
	}
	return 0;
}
*/

/*
	title: 杭电2002 一种：c++
*/
/*
#include <iostream>
using namespace std;
#define PI 3.1415927
int main() {
	double r, acre;
	while (cin >> r) {
		acre = (4 / 3.0)* PI *r*r*r;
		cout.precision(3);
		cout << fixed << acre << endl;
	}
	return 0;
}
*/

/*
	title: 杭电2003 一种：c++
*/
/*
#include <iostream>
#include <Math.h>
using namespace std;
int main() {
	double num, absnum;
	while (cin >> num) {
		absnum = abs(num);
		cout.precision(2);
		cout << fixed << absnum << endl;
	}
	return 0;
}
*/

/*
	title:杭电2004 一种：c++
*/

/*
#include <iostream>
using namespace std;
int  main() {
	int score;
	while (cin >> score) {
		if (score < 0 || score > 100) {
			cout << "Score is error!" << endl;
		}
		else {
			switch (score / 10) {
			case 10:
			case 9: cout << 'A' << endl; break;
			case 8: cout << 'B' << endl; break;
			case 7: cout << 'C' << endl; break;
			case 6: cout << 'D' << endl; break;
			default: cout << 'E' << endl; break;
			}
		}
	}
	return 0;
}
*/

/*
	title: 杭电2005 一种：c
*/

/*
#include <stdio.h>
#include "string.h"

int main() {
	int arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int n, y, r;
	while (scanf("%d/%d/%d", &n, &y, &r) != EOF) {
		int days = 0;
		if ((n % 400 == 0) || (n % 100 != 0 && n % 4 == 0)) {
			arr[2] = 29;
		}else{
			arr[2]=28;
		}
		for (int i = 0; i < y; i++) {
			days += arr[i];
		}
		days += r;
		printf("%d\n", days);

	}

	return 0;
}
*/


/*
	title: 杭电2006 一种：c++
*/

/*
#include <iostream>
using namespace std;

int main() {
	int num, total = 1;
	while (cin >> num) {
		total = 1;
		int m;
		for (int i = 0; i < num; i++) {
			cin >> m;
			if (m % 2 == 1)
				total *= m;
		}
		cout << total << endl;
	}
	return 0;
}
*/

/*
	title: 杭电2007
*/

/*
#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	while (cin >> num1 >> num2) {
		int total1 = 0, total2 = 0;
		int temp = 0;
		if(num1 > num2){
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		for (int i = num1; i <= num2; i++) {
			if (i % 2 == 0)
				total1 = total1 + (i*i);
			else if (i % 2 != 0)
				total2 = total2 +(i*i*i);
		}
		cout << total1 <<' '<< total2 << endl;
	}
	return 0;
}
*/

/*
	title: 杭电2008 
*/

/*
#include <iostream>
using namespace std;

int main() {
	int num;
	while (cin >> num && num != 0) {
			float innum;
			int lnum = 0, znum = 0, rnum = 0;
			for (int i = 0; i < num; i++) {
				cin >> innum;
				if (innum < 0)
					lnum++;
				else if (innum > 0)
					rnum++;
				else
					znum++;
			}
			cout << lnum << ' ' << znum << ' ' << rnum << endl;
	}
	return 0;
}
*/

/*
	title: 杭电2009 一种： c++
*/
/*
#include <iostream>
#include <Math.h>
using namespace std;

int main() {
	int num1,num2;
	while (cin >> num1 >> num2 && num1 < 10000 && num2 < 1000) {
		double total = num1, temp = num1;
		for (int i = 1; i < num2; i++) {
			temp = sqrt(temp);
			total = total + temp;
		}
		cout.precision(2);
		cout << fixed << total << endl;
	}
	return 0;
}
*/

/*
	title: 杭电oj2010
*/
/*
#include <iostream>
#include <Math.h>
using namespace std;

int main() {
	int num1, num2;
	while (cin >> num1 >> num2 && 100<=num1 <= 999 && 100<=num2 <=999) {
		int arr = [];
		int temp;
		int flag = 0;
		if (num1 > num2) {
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		for (int i = num1; i <= num2; i++) {
			int s = i/100;
			int e = (i - s * 100) / 10;
			int y = i - s * 100 - e * 10;
			if (s*s*s + e*e*e + y*y*y == i) {
				flag++;
				if (flag == 1)
					cout << i;
				else
					cout << ' ' << i;
			}
			if (!flag)
				cout << 'no';
			cout << endl;
				
		}
	}
	return 0;
}
*/

/*
	title: 杭电2011 一种 c++
*/

/*
#include <iostream>
#include <Math.h>
using namespace std;

double algor(int num) {
	double value = 0;
	for (int i = 1; i <= num; i++) {
		double m = 1.0/i;
		if (i % 2 == 0)
			m = -1*m;
		value = value + m;
	}
	return value;
}

int main() {
	int num1, num2, num3;
	while (cin >>num1 && num1<100) {
		for (int i = 0; i < num1; i++){
			double value = 0;
			bool flag = 1;
			cin >> num2;
			value = algor(num2);
			if (flag) {
				flag = 0;
				cout.precision(2);
				cout << fixed << value<<endl;
			}
			else {
				cout.precision(2);
				cout << fixed << value;
			}
		}
		
	}
	return 0;
}
*/


/*
	title: 杭电2016  
*/

/*
#include <iostream>
#include <Math.h>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		int *p=new int[num];
		for (int i = 0; i < num; i++) {
			
		}
	}
	return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main(){
	int num, min, j;
	while (cin >> num && num < 100){
		int *p=new int[num];
		for (int i = 0; i < num; i++){
			cin >> p[i];
			if (i == 0){
				min = p[0];
				flag++;
			}else{
				if (min > p[i]){
					min = p[i];
					j = i;
				}
			}
		}
		temp=p[0];
		p[0]=min;
		p[j]=temp;
		for (int i=0;i<n;i++)
		{
			if (i!=0){
				cout<<" ";//数与数之间用空格分开
			}
			cout<<p[i];
		}
		cout<<endl;
		delete p;//记着delete释放空间
	}
	return 0;
}

/*
	title： 杭电2016
*/

/*
#include <iostream>
using namespace std;

int main()
{
int n,min,temp,j;
while (cin>>n&&n!=0)
{
int *p=new int[n];//定义指针并指向用new动态分配大小为n的空间
for (int i=0;i<n;i++)
{
cin>>p[i];
if (i==0)
{
min=p[0];
j=0;
}
else
{
if (p[i]<min)
{
min=p[i];
j=i;
}
}

}
temp=p[0];
p[0]=min;
p[j]=temp;
for (int i=0;i<n;i++)
{
if (i!=0)
{
cout<<" ";//数与数之间用空格分开
}
cout<<p[i];
}
cout<<endl;
delete p;//记着delete释放空间
}
return 0;
}

*/



/*
	title：杭电2017
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	string s;
	while (cin >> num) {
		int total = 0;
		for (int i = 0; i < num; i++) {
			total = 0;
			cin >> s;
			for (int j = 0; j<s.size(); j++) {
				if ((int)s[j] >= (int)'1' && (int)s[j] <= (int)'9')
					total++;
			}
			cout << total << endl;
		}
	}
	return 0;
}
*/

/*
	杭电2013
*/
/*

#include <iostream>
using namespace std;

int main() {
	int num;
	while (cin >> num && num > 1 && num < 30) {
		int total = 1;
		while (num>=2) {
			total = (total + 1) * 2;
			num--;
		}
		cout << total << endl;
	}
	return 0;
}
*/

/*
	
*/

/*
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int num;
	while (cin >> num ) {
		if (num == 0)
			return 0;
		int* p = new int[num];
		for (int i = 0; i < num; i++)
			cin >> p[i];
		sort(p, p+num);
		for (int i = 0; i < num; i++) {
			if (i == 0)
				cout << p[0];
			else
			{
				cout << ' ' << p[i];
			}
		}
		cout << endl;
	}
	return 0;
}
*/

/*
	
*/
/*
#include <iostream>
using namespace std;

int makeNum(int money);

int main() {
	int num, num1;
	while (cin >> num) {
		if (num == 0)
			return 0;
		int total = 0;
		for (int i = 0; i < num; i++) {
			cin >> num1;
			total += makeNum(num1);
		}
		cout << total << endl;
	}
	return 0;
}

int makeNum(int money) {
	int base[] = {100, 50, 20, 10, 5, 2, 1};
	int num = 0;
	for (int i = 0; i < sizeof(base)/sizeof(base[0]); i++) {
		int temp = money / base[i];
		if (temp > 0) {
			num += temp;
			money = money - (base[i]*temp);
		}
	}
	return num;
}
*/