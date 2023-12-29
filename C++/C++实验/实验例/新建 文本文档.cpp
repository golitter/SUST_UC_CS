#include <iostream.h>
const double PI=3.14159265;
class circle
{ public: 
     circle(double r) { radius = r; }
virtual double area() { return 0.0; }
    virtual double volume() { return 0.0; }
  protected:
    double radius;
};
class sphere:public circle
{  public:
     sphere( double r ):circle( r ){ }
     double area() { return 4.0 * PI * radius * radius; }
     double volume()
      { return 4.0 * PI * radius * radius * radius / 3.0; }
};
class column:public circle
{  public:
     column( double r,double h ):circle( r ) { height = h; }
     double area()
       { return 2.0 * PI * radius * ( height + radius ); }
     double volume()
       { return PI * radius * radius * height; }
     private:
       double height;
 };
void main()
{  circle *p;
   sphere sobj(2);
   p = &sobj;
   cout << "����:" << endl;
   cout << "��� = " << p->volume() << endl;
   cout << "����� = " << p->area() << endl;
   column cobj( 3,5 );
   p = &cobj;
   cout << "Բ����:" << endl;
   cout << "��� = " << p->volume() << endl;
   cout << "����� = " << p->area() << endl;
}
