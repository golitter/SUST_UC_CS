#include <iostream>

#define _USE_MATH_DEFINES 
#include <cmath>
using namespace std;

namespace golitter {
namespace lab4 {

class Circle {
public:
    Circle() {}
    Circle(double r):m_radius(r) {}
    virtual double area();
    virtual double volume();
    double get_radius();
private:
    double m_radius;
};
// 求面积
double Circle::area() {
    return m_radius*m_radius*M_PI;
}
// 求体积
double Circle::volume() {
    return 0;
}
// 半径
double Circle::get_radius() {
    return m_radius;
}

class Sphere: public Circle {
public:
    Sphere() {}
    Sphere(double r): Circle(r) {}
    virtual double area();
    virtual double volume();
private:
};
// 求面积
double Sphere::area() {
    return get_radius()*get_radius()*4*M_PI;
}
// 求体积
double Sphere::volume() {
    return 4.0/3*pow(get_radius(),3)*M_PI;
}

class Column: public Circle {
public:
    Column() {}
    Column(double r, double h): Circle(r), m_height(h) {}
    virtual double area();
    virtual double volume();    
private:
    double m_height;
};
// 求面积
double Column::area() {
    double ar = Circle::area()*2;
    ar += 2*M_PI*get_radius()*m_height;
    return ar;
}
// 求体积
double Column::volume() {
    return Circle::area()*m_height;
}

}}

using golitter::lab4::Column;
void solve() {
    // Column c(3,4);
    // cout<<c.area();
}
int main() 
{
    solve();
}