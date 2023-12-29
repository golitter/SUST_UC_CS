#include <iostream>
using namespace std;
#include "date.h"

int main()
{
	
	Date date1(2021,9,17);
	Date date2(date1);
	Date date3(2021,10);
	Date date4;


	cout<<sizeof(date2)<<endl;
	
	cout<<"The date:";
	date3.Print_date('-');	
	
	if(date2.Isleap())
		cout<<"is a leap years."<<endl;
	else
		cout<<"is not a leap years."<<endl;
	
	cout<<"The days:"<<date2.SumDays()<<endl;

	cout<<"The day:"<<date2.Get_day()<<endl;













	/*int year,month,day,S=0;

	cout<<"Please input a date:yyyy mm dd:";
	cin>>year>>month>>day;
	
	S=SumDays(year,month,day);


	cout<<"The date:"<<year<<"/"<<month<<"/"<<day<<endl;
	cout<<"The days:"<<S<<endl;
*/

	return 0;
}