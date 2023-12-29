#include <iostream>
#include <string>
using namespace std;
namespace golitter {
namespace lab2 {

class Student {
    friend istream& operator>>(istream& in, Student &rhs);
public:
    Student():m_hadSignReg(false) {}
    void print_prompt_message();
    void set_all_info();
    void set_score(double score);
    void set_name(string& name);
    void print_all_info();
private:
    string m_name;
    double m_score;
    bool m_hadSignReg;
    string m_examReg_number; // ׼��֤�� examRegistrationNumber

};
istream& operator>>(istream& in, Student &rhs) {
    if(rhs.m_hadSignReg != true) {
        in>>rhs.m_examReg_number;
        rhs.m_hadSignReg = true;
    }
    in>>rhs.m_name>>rhs.m_score;
    return in;
}
// ��ӡ������ʾ��Ϣ
void Student::print_prompt_message() {
    cout<<"���������룺";
    if(this->m_hadSignReg != true) {
        cout<<"׼��֤�� ";
        // this->hadSignReg = true;
    }
    cout<<"���� ���˳ɼ�\n";
}
// Ϊ׼��֤���������ɼ� ��ֵ
void Student::set_all_info() {
    print_prompt_message();
    cin>>(*this);
}
// Ϊ�ɼ���ֵ
void Student::set_score(double score) {
    this->m_score = score;
}
// Ϊ���ָ�ֵ
void Student::set_name(string& name) {
    this->m_name = name;
}
// ��ӡ������Ϣ
void Student::print_all_info() {
    cout<<"׼��֤�ţ�"<<this->m_name<<"  "<<"������"<<this->m_name<<"  �Ŷӳɼ���"<<this->m_score<<'\n';
}

}}
using golitter::lab2::Student;
void solve() {
    // Student a; a.set_all_info();
    // a.set_all_info();
}
int main()
{
    solve();
    return 0;
}