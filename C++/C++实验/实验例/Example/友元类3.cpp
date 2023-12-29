#include <iostream.h>
#include <string.h>
class Student
{
	friend class FriendStudent;
	public:
		Student(char N[],int i)
		{
			strcpy(name,N);
			score=i;
			total_score+=i;
			count++;
		}
	private:
		char name[30];
		int score;
		static int total_score;
		static int count;
};
int Student::total_score=0;
int Student::count=0;
class FriendStudent
{
	public:
		void Disp(Student &s)
		{
			cout<<s.name<< "Student's Score is:"<<s.score<<endl;
		}
		void Total()
		{
			cout<<Student::count<<" students score:"<<Student::total_score<<endl;
		}
};
void main()
{
	Student s1("Li Yi",100),s2("Gao Yang",66),s3("Li Yang",88);
	FriendStudent fs;
	fs.Disp(s1);
	fs.Disp(s2);
	fs.Disp(s3);
	fs.Total();

}
