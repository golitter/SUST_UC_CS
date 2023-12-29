#include <iostream>
#include <cstring>
using namespace std;
namespace golitter {
namespace lab4 {

class MyString {
public:
    MyString() {}
    MyString(const char* str) {
        int len = strlen(str);
        ptr_str = new char [len+1];
        strcpy(ptr_str, str);
    }
    void info();
    ~MyString() {
        delete [] ptr_str;
    }
    MyString& operator+(const MyString& rhs);
private:
    char* ptr_str = nullptr;
};
MyString& MyString::operator+(const MyString& rhs) {
    char* ptr_tmp;
    int len = strlen(this->ptr_str) + strlen(rhs.ptr_str) + 1;
    ptr_tmp = new char[len];
    strcpy(ptr_tmp, this->ptr_str);
    strcat(ptr_str, rhs.ptr_str);
    return MyString(ptr_str);
}
void MyString::info() {
    cout<<this->ptr_str<<'\n';
}
}}
using golitter::lab4::MyString;

void solve() {
    MyString ms("dklfjkldjf");
    MyString ms1("1234563245");
    MyString c = ms + ms1;
    c.info();
}
int main()
{
    solve();
}