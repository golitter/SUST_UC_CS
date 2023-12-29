#include <iostream>
#include <string>
using namespace std;
namespace golitter
{
    namespace lab2
    {

        class Student
        {
            friend istream &operator>>(istream &in, Student &rhs);

        public:
            Student() : m_hadSignReg(false) {}
            void print_prompt_message();
            void set_all_info();
            void set_score(double score);
            void set_name(string &name);
            void print_all_info();

        private:
            string m_name;
            double m_score;
            bool m_hadSignReg;
            string m_examReg_number; // 准考证号 examRegistrationNumber
        };
        istream &operator>>(istream &in, Student &rhs)
        {
            if (rhs.m_hadSignReg != true)
            {
                in >> rhs.m_examReg_number;
                rhs.m_hadSignReg = true;
            }
            in >> rhs.m_name >> rhs.m_score;
            return in;
        }
        // 打印输入提示信息
        void Student::print_prompt_message()
        {
            cout << "请依次输入：";
            if (this->m_hadSignReg != true)
            {
                cout << "准考证号 ";
                // this->hadSignReg = true;
            }
            cout << "姓名 个人成绩\n";
        }
        // 为准考证、姓名、成绩 赋值
        void Student::set_all_info()
        {
            print_prompt_message();
            cin >> (*this);
        }
        // 为成绩赋值
        void Student::set_score(double score)
        {
            this->m_score = score;
        }
        // 为名字赋值
        void Student::set_name(string &name)
        {
            this->m_name = name;
        }
        // 打印所有信息
        void Student::print_all_info()
        {
            cout << "准考证号：" << this->m_name << "  "
                 << "姓名：" << this->m_name << "  团队成绩：" << this->m_score << '\n';
        }

    }
}
using golitter::lab2::Student;
void solve()
{
    // Student a; a.set_all_info();
    // a.set_all_info();
}
int main()
{
    solve();
    return 0;
}
