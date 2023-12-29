#include <iostream>
#include <iomanip>
using namespace std;
void Input_Message(char (*Name)[20], int (*Score)[4], int n);
void output_message(char (*Name)[20], int (*Score)[4], int *TotalScore, int n, float *AverScore, int m);
void main()
{
	// 1
	int i, j;
	char Name[3][20] = {""};
	int Score[3][4] = {0};
	int TotalScore[3] = {0};
	float AverScore[4] = {0.0};
	// 2
	Input_Message(Name, Score, 3);

	output_message(Name, Score, TotalScore, 3, AverScore, 4);
}
void Input_Message(char (*Name)[20], int (*Score)[4], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << "Input Names(3):";
		cin.getline(Name[i], 20);
	}
	for (i = 0; i < n; i++)
	{
		cout << "Input Scores(4):";
		for (j = 0; j < 4; j++)
			cin >> Score[i][j];
	}
}
void output_message(char (*Name)[20], int (*Score)[4], int *TotalScore, int n, float *AverScore, int m)
{
	int i, j;
	cout << endl
		 << endl;
	cout << setw(10) << "Name" << setw(10) << "SCore1";
	cout << setw(10) << "SCore2" << setw(10) << "SCore3";
	cout << setw(10) << "SCore4" << setw(10) << "Total" << endl;
	for (i = 0; i < n; i++)
	{
		cout << setw(10) << Name[i];

		for (j = 0; j < m; j++)
			cout << setw(10) << Score[i][j];

		cout << setw(10) << TotalScore[i];

		cout << endl;
	}

	cout << setw(10) << "AverScore";
	for (i = 0; i < m; i++)
		cout << setw(10) << AverScore[i];
	cout << endl;
}