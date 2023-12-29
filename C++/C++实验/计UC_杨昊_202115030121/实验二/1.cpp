#include <iostream>
using namespace std;
namespace golitter {
namespace lab2 {
class CostOfAround {
public:
    CostOfAround() {}
    void calculate_aislePrice();
    void calculate_fencePrice();
    void info();
    void input_r();
    const double PI = 3.1415962;
private:
    double m_r;
    double aislePrice;
    double fencePrice;
    void read_r(double r);
};
static double PI = 3.1415962;
void CostOfAround::read_r(double r) {
    m_r = r;
}
// ������Ӿ�ذ뾶
void CostOfAround::input_r() {
    cout<<"������뾶��";
    double tmp; cin>>tmp;
    read_r(tmp);
}
// ����դ�������
void CostOfAround::calculate_aislePrice() {
    fencePrice = m_r*2*PI + (m_r + 3)*2*PI;
    fencePrice = fencePrice * 35;
}
// ������������
void CostOfAround::calculate_fencePrice() {
    aislePrice = PI*( (m_r + 3) * (m_r + 3) - (m_r)*(m_r));
    aislePrice = aislePrice * 20; 
}
// ��ӡ��Ϣ
void CostOfAround::info() {
    input_r();
    calculate_aislePrice();
    calculate_fencePrice();
    cout<<"��Ӿ�ذ뾶Ϊ��"<<m_r<<'\n';
    cout<<"�������Ϊ��"<<aislePrice<<'\n';
    cout<<"դ�����Ϊ��"<<fencePrice<<'\n';
}
}}
using golitter::lab2::CostOfAround;
void solve() {
    CostOfAround a;
    a.info();
}
int main() 
{
    solve();
    return 0;
}
