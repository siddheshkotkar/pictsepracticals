#include<iostream>
using namespace std;
class complex
{
public:
	float x,y;//Complex number elements i.e real and imaginary part
	complex()
	{
		x=0;//real part
		y=0;//imaginary part
	}

	complex operator+(complex a)//overloading + operator
	{
		complex local;//for storing result
		local.x=a.x+x;
		local.y=a.y+y;
		return local;//returning result
	}

	complex operator*(complex a)//overloading * operator
	{
		complex local;
		local.x=(x*a.x)-(y*a.y);
		local.y=(y*a.x)+(a.y*x);
		return local;
	}

	friend istream &operator>>(istream &ip, complex &a)//overloading >> operator
	{
		cout<<"Enter the real part:";
		ip>>a.x;
		cout<<"Enter the imaginary part:";
		ip>>a.y;

	}

	friend ostream &operator<<(ostream &op,complex &a)//overloading << operator
	{
		op<<a.x<<"+"<<a.y<<"i"<<endl;

	}

};

int main()
{
	complex c1,c2,c3,c4;//creating complex type objects
	cin>>c1;//calling >> operator
	cin>>c2;//calling << operator
	int op;
	do
	{

	cout<<endl;
	cout<<"1.Addition"<<endl;
	cout<<"2.Multiplication"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter your choice:"<<endl;;
	cin>>op;
	switch(op)
	{
	case 1:
		c3=c1+c2;//calling + operator
		cout<<c3;//calling << operator
		break;
	case 2:
		c4=c1*c2;//calling * operator
		cout<<c4;//calling << operator
		break;
	case 3:
		break;
	}
	}while(op!=3);
}
