const int month_day[13]={0,31,28,31,30,31,30,
                           31,31,30,31,30,31};
bool Is_Leap(int year)
{
	return (year%4==0&&year%100!=0||year%400==0);
}
int Sum_Days(int year,int month,int day)
{  //2020/10/15
	int S=0,i;
	//1
	for(i=1;i<month;i++)
		S=S+month_day[i];
	//2
	S=S+day;
    //3
	if(Is_Leap(year)&&month>2)
		S=S+1;
	return S;
}