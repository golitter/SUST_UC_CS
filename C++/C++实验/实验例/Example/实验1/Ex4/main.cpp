#include <iostream>
#include <iomanip>
using namespace std;
const int M=3;
const int N=4;
void Input(char (*Name)[20],float (*Score)[N],int M)
{
	int i,j;
	for(i=0;i<M;i++)
	{
		cout<<"Input name:";
		cin.getline(Name[i],20);
	}
	for(i=0;i<M;i++)
	{

		cout<<"Input 4 scores:";
		for(j=0;j<N;j++)
			cin>>Score[i][j];
	}
}
void Comput_Score(float (*Score)[N],float *Total,int M)
{
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		Total[i]=Total[i]+Score[i][j];
	
	}
}
int main()
{
	//1
	int i,j;
	char Name[M][20]={"\0"};
	float Score[M][N]={0};
	float Total[M]={0.0};
	float Aver[N]={0.0};
	//2
	Input(Name,Score, M);

	//3-1
	Comput_Score(Score,Total,M);

	//3-2
	for(i=0;i<N;i++)
	{		
		for(j=0;j<M;j++)
			Aver[i]=Aver[i]+Score[j][i];
		Aver[i]=Aver[i]/M;
	
	}




	//4
	cout<<setw(10)<<"Name"<<setw(10)<<"Corse1";
	cout<<setw(10)<<"Corse2"<<setw(10)<<"Corse3";
	cout<<setw(10)<<"Corse4"<<setw(10)<<"Total"<<endl;
	for(i=0;i<M;i++)
	{
		cout<<setw(10)<<Name[i];
		for(j=0;j<N;j++)
			cout<<setw(10)<<Score[i][j];
		cout<<setw(10)<<Total[i];
		cout<<endl;
	}
	cout<<setw(10)<<"";
	for(j=0;j<N;j++)
		cout<<setw(10)<<Aver[j];
	cout<<endl;




	return 0;
}