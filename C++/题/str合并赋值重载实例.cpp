#include <iostream.h>
#include <string.h>

class MyString
{
	public:
		MyString()
		{
			str =0;
		}
		MyString(char *s)
		{
			str=new char[strlen(s)+1];
			strcpy(str,s); 
		}
		~MyString()
		{
			delete[]str;
		}
		void PrintSelf()
		{
			cout<<str<<endl;
		}
		MyString(const MyString & rhs) {
			delete [] str;
			str = new char[strlen(rhs.str) + 1];
			strcpy(str, rhs.str);
		}
		MyString& operator +(MyString &b) //字符串连接
		{
			char* temp =this->str;
			str = new char[strlen(temp)+strlen(b.str)+1];  
			strcpy(str,temp);
			delete temp;
			strcat(str,b.str);
			return *this;
		}
		MyString& operator =(MyString &c) // 赋值函数
		{
			if(this == &c)return *this; //检查自赋值
			delete str; // 释放原有的内存资源
			str = new char[strlen(c.str )+1]; // 分配新的内存资源
			strcpy(str,c.str); // 并复制内容
			return *this; // 返回本对象的引用
		}
		
	private:
		char *str; 
};

void main()
{ 
	MyString a;
	MyString b("BBB"),c("CCC");
	MyString c(a);
	a=b+c;
	a.PrintSelf(); 

}
