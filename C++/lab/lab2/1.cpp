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
// 读入游泳池半径
void CostOfAround::input_r() {
    double tmp; cin>>tmp;
    read_r(tmp);
}
// 计算过道的造价
void CostOfAround::calculate_aislePrice() {
    aislePrice = m_r*2*PI + (m_r + 3)*2*PI;
}
// 计算栅栏的造价
void CostOfAround::calculate_fencePrice() {
    fencePrice = PI*( (m_r + 3) * (m_r + 3) - (m_r)*(m_r));
}
// 打印信息
void CostOfAround::info() {
    input_r();
    calculate_aislePrice();
    calculate_fencePrice();
    cout<<"游泳池半径为："<<m_r<<'\n';
    cout<<"过道造价为："<<aislePrice<<'\n';
    cout<<"栅栏造价为："<<fencePrice<<'\n';
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