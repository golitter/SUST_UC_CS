#include <iostream>
#include <string>
using namespace std;
namespace golitter{
namespace lab3 {
class Building {
public:
    Building() {}
    Building(string address, signed short number):m_address(address), m_buildingNumber(number) {}
    string get_address();
    signed short get_buildingNumber();
    void info();
private:
    string m_address;
    signed short m_buildingNumber;
};
// 获得Build地址
string Building::get_address() {
    return this->m_address;
}
signed short Building::get_buildingNumber() {
    return this->m_buildingNumber;
}
// 打印信息
void Building::info() {
    cout<<this->m_address<<" "<<this->m_buildingNumber<<'\n';
}

class House: public Building {
public:
    House() {}
    House(string address, signed short buildNumber, double area, signed short houseNumber):
        Building(address, buildNumber),
            m_area(area), m_houseNumber(houseNumber) {}
    void info();

private:
    double m_area;
    signed short m_houseNumber;
};
// 打印信息
void House::info() {
    cout<<get_address()<< " "<<get_buildingNumber()<< " "
            <<m_houseNumber<< " "<<m_area<<'\n';
}

class Office: public Building {
public:
    Office() {}
    Office(string address, signed short buildNumber, string officeName, string officePhoneNumber):
        Building(address, buildNumber), 
            m_officeName(officeName), m_officePhoneNumber(officePhoneNumber) {}
    void info();
private:
    string m_officeName;
    string m_officePhoneNumber;
};
// 打印信息
void Office::info() {
    cout<<get_address()<<" "<<get_buildingNumber()<<" "
            <<m_officeName<<" "<<m_officePhoneNumber<<'\n';
}

}}
using namespace golitter::lab3;

void solve() {
    // Office o("add", 34,"dkjfkdfj", "2345234");
    // o.info();
}
int main()
{
    solve();
    return 0;
}