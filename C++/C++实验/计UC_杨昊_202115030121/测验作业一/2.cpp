/*1.����ĳ���ꡢ�¡��յ�ֵ������2008��4��7�ա�
�������һ�����ڸ���ĵڼ��졣
Ҫ��д����������ĺ����ͼ������ڵĺ�����*/
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
	// 1��������
	int year, month, day;

	// 2���벿��
	cout << "Please input a date(yyyy mm dd):" << endl;
	cin >> year >> month >> day;

	// 3�������㡪���㷨

	// 4���

	cout << year << "." << month << "." << day << endl;

	if (IsLeapYear(year))
		cout << "This year is a leap year" << endl;
	else
		cout << "This year is not a leap year" << endl;
	cout << "The date is the " << SumDays(year, month, day) << "th days of this year." << endl;

	return 0;
}
