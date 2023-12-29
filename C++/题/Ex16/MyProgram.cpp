#include <iostream.h>
#include "Shape.h"
#include "App1.h"
void main()
{
	Tpoint p1,p2(1,2);
	Tcircle c1,c2(1,2,3);
	Tarc a1,a2(1,2,3,30,60);
	Tcylinder cy1,cy2(1,2,3,4);
	Tapp ap1;
	p1=c1;
	cout<<"---------------------"<<endl;
	cout<<"¼Û¸ñ£º"<<ap1.Price(a2)<<endl;
	cout<<"---------------------"<<endl;
	
}