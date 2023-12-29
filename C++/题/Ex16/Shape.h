const double Pi=3.1415926;
class Tshape
{
	public:
		virtual double Area()=0;
};
class Tpoint:public Tshape
{
	public:
		//系统接口
		Tpoint(int xx=0,int yy=0);
		virtual ~Tpoint(){}
		//用户接口
		virtual double Area(){return 0.0;}
		void Set_point(int xx=0,int yy=0);
		void Mov_point(int xx=0,int yy=0);
		int Get_x()const{return this->x;}
		int Get_y()const{return this->y;}	
		void Print()const ;
	
		
	private:
		int x,y;
};

class Tcircle:public Tpoint
{
	public:
		//系统接口
		Tcircle(int xx=0,int yy=0,double r=0)
		:Tpoint(xx,yy)
		{
			radius=r;
			cout<<"Circle con.\n";		
		}
	
		//用户接口
		double Area();
		double Perimeter();
		void Set_radius(double r=0);
		double Radius();
	protected:
		double radius;
};
class Tarc:public Tcircle
{
	public:
		Tarc(int xx=0,int yy=0,double r=0,double sa=0,double ea=0): Tcircle(xx,yy,r)
		{
			StartAngle=sa,EndAngle=ea;
			cout<<"Arc con.\n";
		}
		~Tarc()
		{
			cout<<"Arc des.\n";
		}
		double Area();
	
	private:
		double StartAngle,EndAngle;
};
class Tcylinder:public Tcircle
{
	public:
		Tcylinder(int xx=0,int yy=0,double r=0,double hh=0): Tcircle(xx,yy,r)
		{
			h=hh;
			cout<<"Cylinder con.\n";
		}
		~Tcylinder()
		{
			cout<<"Cylinder des.\n";
		}
		double Area();
	
	private:
		double h;
};

double Tcircle::Area()
{
	return Pi*radius*radius;
}
double Tarc::Area()
{
	return (EndAngle-StartAngle)/360*(Tcircle::Area());
}
double Tcylinder::Area()
{
	return 2*(Tcircle::Area())+2*Pi*radius*h;
}
double Tcircle::Perimeter()
{
	return 2*Pi*radius;
}
void Tcircle::Set_radius(double r)
{
	radius=r;
}
double Tcircle::Radius()
{
	return radius;
}
Tpoint::Tpoint(int xx,int yy)
{
	this->x=xx;y=yy;
	cout<<"Point con.\n";
}
void Tpoint::Set_point(int xx,int yy)
{
	this->x=xx;this->y=yy;
}
void Tpoint::Mov_point(int xx,int yy)
{
	x=x+xx;y=y+yy;
}
void Tpoint::Print()const
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}