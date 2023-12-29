#include <iostream>
using namespace std;
#include "date.h"
int main()
{
	//1
	int year,month,day;
	//2
	cout<<"Please input data(xxxx xx xx):";
	cin>>year>>month>>day;
	//3

	//4
	cout<<"data:"<<year<<"/"<<month<<"/"<<day<<endl;
	if(Is_Leap(year))
		cout<<"Yes\n";
	else
		cout<<"No\n";
	cout<<"Sum_Days:"<<Sum_Days(year,month,day)<<endl;



	return 0;
}