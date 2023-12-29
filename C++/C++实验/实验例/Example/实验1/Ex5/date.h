const int month_day[13]={0,31,28,31,30,31,30,
                           31,31,30,31,30,31};
class TDate
{
public:
	//系统接口
	TDate(){cout<<"Default\n";}//默认构造函数
    TDate(int y,int m,int d);//普通构造函数
	TDate(int y);
	~TDate(){cout<<"Decon"<<endl;}
	//用户接口
//	void Input();
	bool Is_Leap();
	int Sum_Days();
	void Set_Date(int y,int m,int d);
	void Output();
private:
	int year,month,day;

};
void TDate::Output()
{
	cout<<"data:"<<year<<"/"<<month<<"/"<<day<<endl;
}
TDate::TDate(int y,int m,int d)
{	cout<<"Con.\n";
	year=y,month=m,day=d;	
}
TDate::TDate(int y)
{	cout<<"Con3.\n";
	year=y;	
}
void TDate::Set_Date(int y,int m,int d)
{
	year=y,month=m,day=d;
	
}
bool TDate::Is_Leap()
{
	return (year%4==0&&year%100!=0||year%400==0);
}
int TDate::Sum_Days()
{  //2020/10/15
	int S=0,i;
	//1
	for(i=1;i<month;i++)
		S=S+month_day[i];
	//2
	S=S+day;
    //3
	if(Is_Leap()&&month>2)
		S=S+1;
	return S;
}
