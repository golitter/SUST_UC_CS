#include <iostream>
using namespace std;
#include "date.h"
int main()
{
	TDate d1(2020,10,22);
	TDate d2;
	TDate d3(d1);

	
	d1.Output();
	if(d1.Is_Leap())
		cout<<"Yes\n";
	else
		cout<<"No\n";
	cout<<"Sum_Days:"<<d1.Sum_Days()<<endl;
	cout<<"-------------------------"<<endl;
	d2.Set_Date(2019,10,22);
	d2.Output();
	if(d2.Is_Leap())
		cout<<"Yes\n";
	else
		cout<<"No\n";
	cout<<"Sum_Days:"<<d2.Sum_Days()<<endl;
	cout<<"-------------------------"<<endl;
	d3.Output();
	
	










/*//1
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


*/
	return 0;
}