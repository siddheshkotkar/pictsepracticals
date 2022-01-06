#include<bits/stdc++.h>
using namespace std;
class complex
{
	float x,y;
	public:
		complex()
		{
			x=0;
			y=0;
		}
		
		friend istream &operator>>(istream &input,complex &t)
		{
			cout<<"Enter the real part:"<<endl;
			input>>t.x;
			cout<<"Enter the imaginary part"<<endl;
			input>>t.y;
		}
		friend ostream &operator<<(ostream &output,complex &t)
		{
			output<<t.x<<" + "<<t.y<<"i";
		}
		
		complex operator+(complex a)
		{
			complex temp;
			temp.x=this->x+a.x;
			temp.y=y+a.y;
			return temp;
		}
		
		complex operator*(complex a)
		{
			complex temp;
			temp.x=x*a.x;
			temp.y=y*a.y;
			return temp;
		}
};

int main()
{
	::complex c1,c2,c3,c4;
	cout<<"Practical no.1"<<endl;
	cout<<"Enter the first number:"<<endl;
	cin>>c1;
	cout<<"Enter the second number:"<<endl;
	cin>>c2;
	c3=c1+c2;
	c4=c1*c2;
	cout<<"First number is:"<<c1<<endl;
	cout<<"Second number is:"<<c2<<endl;
	cout<<"Their addition is:"<<c3<<endl;
	cout<<"Their multiplication is:"<<c4<<endl;
	cout<<"Thankyou";
	
}
