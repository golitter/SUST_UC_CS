/*1.给定某个年、月、日的值，例如2008年4月7日。
计算出这一天属于该年的第几天。
要求写出计算闰年的函数和计算日期的函数。*/
#include <iostream>
using namespace std;

const int MonthDays[13] =
	{0, 31, 28, 31, 30, 31, 30,
	 31, 31, 30, 31, 30, 31};

bool IsLeapYear(const int &y)
{
	return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}
int SumDays(int year, int month, int day)
{
	int S = 0;
	for (int i = 1; i < month; i++)
		S = S + MonthDays[i];

	S = S + day;

	if (IsLeapYear(year) && month > 2)
		S = S + 1;

	return S;
}

int main()
{
	// 1变量定义
	int year, month, day;

	// 2输入部分
	cout << "Please input a date(yyyy mm dd):" << endl;
	cin >> year >> month >> day;

	// 3处理、计算——算法

	// 4输出

	cout << year << "." << month << "." << day << endl;

	if (IsLeapYear(year))
		cout << "This year is a leap year" << endl;
	else
		cout << "This year is not a leap year" << endl;
	cout << "The date is the " << SumDays(year, month, day) << "th days of this year." << endl;

	return 0;
}
