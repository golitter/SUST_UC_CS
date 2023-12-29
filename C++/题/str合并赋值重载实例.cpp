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
		MyString& operator +(MyString &b) //�ַ�������
		{
			char* temp =this->str;
			str = new char[strlen(temp)+strlen(b.str)+1];  
			strcpy(str,temp);
			delete temp;
			strcat(str,b.str);
			return *this;
		}
		MyString& operator =(MyString &c) // ��ֵ����
		{
			if(this == &c)return *this; //����Ը�ֵ
			delete str; // �ͷ�ԭ�е��ڴ���Դ
			str = new char[strlen(c.str )+1]; // �����µ��ڴ���Դ
			strcpy(str,c.str); // ����������
			return *this; // ���ر����������
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
