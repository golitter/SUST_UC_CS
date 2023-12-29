
const int MonthDays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class   Date
{
	public:
		//系统接口
		Date(int y=2010,int m=1,int d=1);//普通构造函数

		Date(Date & p)
		{
				this->year=p.year;
				this->month=p.month;
				this->day=p.day;
				cout<<"Copy Default Destructor called."<<endl;

		}
		

        ~Date(){cout<<"De Destructor called."<<endl;}


		//用户接口
		void Input_date();
		void Set_date(int y,int m,int d);
		bool Isleap();
		void Print_date();
		void Print_date(int );
		int SumDays();
		int Get_day(){return day;}
	private://Protected
		int year;
		int month;
		int day;
		//int *p;
};
Date::Date(int y,int m,int d)
{
	year=y,month=m,day=d;
	cout<<"Destructor called."<<endl;
}

void Date::Set_date(int y,int m,int d)
{
	year=y,month=m,day=d;

}
void Date::Input_date()
{
	cin>>year>>month>>day;

}
void Date::Print_date()
{
	cout<<year<<"/"<<month<<"/"<<day<<endl;
}
void Date::Print_date(int )
{
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}
bool Date::Isleap()
{
	return (year%4==0&&year%100!=0||year%400==0);
}
int Date::SumDays()
{//2021 9 28
	int S=0;
	//1
	for(int i=1;i<month;i++)
		S=S+MonthDays[i];
	//2
	S=S+day;

	//3+1
	if(Isleap()&&month>2)
		S=S+1;
	return S;
}
