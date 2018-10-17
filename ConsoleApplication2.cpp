

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

