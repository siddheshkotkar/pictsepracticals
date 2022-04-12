#include<bits/stdc++.h>
#define MAX 10
using namespace std;
struct details
{
	long long int phNo;
};
class get_details
{
	public:
		long long int x,temp;
		details d[MAX];
		
		void initialise()
		{
			for(int i=0;i<MAX;i++)
			{
				d[i].phNo=0;
			}
		}
		
		void accept()
		{
			int index;
			char ch;
			do{
			
			cout<<"\n Enter phone number:";
			cin>>x;
			index=x%MAX;
//			cout<<index;
			for(int i=0;i<MAX;i++)
			{
				if(d[index].phNo==0)
				{
					d[index].phNo=x;
					break;
				}
				else if(d[index].phNo!=0)
				{
					temp=d[index].phNo;
					d[index].phNo=x;
					for(int i=index;i<MAX;i++)
					{
						if(d[i].phNo==0)
						{
							d[i].phNo=temp;
						}
					}
				}
				else
				{
					index=index+1;
				}
			}
			cout<<"(y/n):";
			cin>>ch;
		}while(ch!='n');
		}
		void print()
		{
			for(int i=0;i<MAX;i++)
			{
				cout<<"\n"<<d[i].phNo;
			}
		}
				
};
int main()
{
	get_details g;
	g.initialise();
	char choice;
	do
	{
		cout<<"\n1.Accept";
		cout<<"\n2.Print";
		cout<<"\n3.Exit";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				g.accept();
				break;
			case 2:
				g.print();
				break;
			
		}
	}while(choice!=3);
}
