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
		
		int search(details a[MAX],long long int fkey)
		{
			for(int i=0;i<MAX;i++)
			{
				if(a[i].phNo==fkey)
				{
					return i;
				}
			}
			return 0;
		}
		
		int find_duplicate(details a[MAX],long long int fkey)
		{
			for(int i=0;i<MAX;i++)
			{
				if(d[i].phNo==x)
					return 1;
					
			}
			return 0;
		}
		
		void hash_Nreplacement()
		{
			char ch;
			do{
			cout<<"\nEnter phone number:";
			cin>>x;
			int dup=find_duplicate(d,x);
			if(dup==1)
			{
			cout<<"\nDuplicate entered!";
			continue;
			}
			else
			{
			
				int index;
				index=(x%MAX);
				if(d[index].phNo==0)
				{
				d[index].phNo=x;
				
				}
				else
				{
				for(int i=index;i<MAX;i++)
				{
					if(d[i].phNo==0)
					{
						d[i].phNo=x;
						break;
					}
				}
				
			}
		}
			cout<<"\n Do you want to continue adding?(y/n):";
			cin>>ch;
			}while(ch!='n');
			cout<<"\n Enter element to search:";
			cin>>temp;
			int ans=search(d,temp);
			if(ans!=0)
				cout<<"\n Phone number found at location "<<ans;
			else
				cout<<"\n Element not found";

		}
		
		void hash_Wreplacement()
		{
			char ch;
			do{
			
			cout<<"\nEnter phone number:";
			cin>>x;
			int dup=find_duplicate(d,x);
			if(dup==1)
			{
			cout<<"\nDuplicate entered!";
			continue;
			}
			else
			{
			
			int index,tmp_index;
			index=(x%MAX);
			
			if(d[index].phNo==0)
			{
				d[index].phNo=x;
				tmp_index=index;
			}
			else if(d[index].phNo!=0 && index==tmp_index)
			{
				for(int i=index;i<MAX;i++)
				{
					if(d[i].phNo==0)
					{
						d[i].phNo=x;
						break;
					}
				}
			}
			else
			{
				if(d[index].phNo!=0)
				{
					temp=d[index].phNo;
					d[index].phNo=x;
				}
				for(int i=index;i<MAX;i++)
				{
					if(d[i].phNo==0)
					{
						d[i].phNo=temp;
						break;
					}
				}
				
			}
		}
		cout<<"\n Do you want to continue(y/n):";
		cin>>ch;
		}while(ch!='n');
		cout<<"\n Enter element to search:";
		cin>>temp;
		int ans=search(d,temp);
		if(ans!=0)
			cout<<"\n Phone number found at location "<<ans;
		else
			cout<<"\n Element not found";
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
	int choice;
	do
	{
		cout<<"\n1.Without replacement";
		cout<<"\n2.With replacement";
		cout<<"\n3.Print";
		cout<<"\n4.Exit";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				g.hash_Nreplacement();
				break;
			case 2:
				g.hash_Wreplacement();
				break;
			case 3:
				g.print();
				break;
			
		}
	}while(choice!=4);
}
