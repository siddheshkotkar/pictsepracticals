#include<bits/stdc++.h>
using namespace std;
class publication
{
	public:
	string title;
	float price;
};

class pgcnt:public publication
{
	public:
	int page_count;
};

class playingtime:public publication
{
	public:
	float minutes;
};

int main()
{
	int n;
	cout<<"Enter the number of record you want to enter:";
	cin>>n;
	playingtime p1[n];
	pgcnt p2[n];
	int i=0;
	while(i<n)
	{
		cout<<"Enter the title of the book:";
		cin>>p1[i].title;
		cout<<"Enter the price of the book:";
		cin>>p1[i].price;
		cout<<"Enter the number of pages in the book:";
		cin>>p2[i].page_count;
		cout<<"Enter the tape playing time in minutes:";
		cin>>p1[i].minutes;
		i++;
}
		try
		{
			int x=-1;
			for(int i=0;i<n;i++)
			{
			
			if(p2[i].page_count<=0)
			{
				
				p1[i].price=0;
//				p1[i].title="\0";
				p1[i].minutes=0;
				throw x;
			}
		}
			
		}
		catch(int x)
		{
			cout<<"Exception catched"<<endl;
		}
		cout<<"The inputted data is:"<<endl;
		for(int i=0;i<n;i++)
		{
		
		cout<<"Title :"<<p1[i].title<<endl;
		cout<<"Price :"<<p1[i].price<<endl;
		cout<<"Page count :"<<p2[i].page_count<<endl;
		cout<<"Tape playing :"<<p1[i].minutes<<endl;
	}

	
	
	
	

}
