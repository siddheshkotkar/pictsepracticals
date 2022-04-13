/*
 * pr4.cpp
 *
 *  Created on: 01-Apr-2022
 *      Author: pict
 */

#include<bits/stdc++.h>
#define max 10
using namespace std;
class node
{
public:
	long int phNo;
};
class hashTable:node
{
public:
	node n[max];
	hashTable()
	{
		for(int i=0;i<max;i++)
		{
			n[i].phNo=0;
		}
	}
	void create_Hashtable()
	{
		long int n1;
		int index;
		char ch;
		do
		{
			cout<<"Enter phone number:\n";
			cin>>n1;
			for(int i=0;i<max;i++)
			{
				if(n[i].phNo==n1)
				{
					cout<<"Sorry number's already added";
					break;
				}
				else{
					index=(n1%max);
				for(int i=0;i<max;i++)
				{
				if(n[index].phNo==0)
				{
					n[index].phNo=n1;
					break;
				}
				else
				{
					index=(index+1)%max;

				}
				}
				}
			}
			
			cout<<"\nDo you want to add more numbers(y/n):\n";
			cin>>ch;
		}while(ch!='n');
	}
	void with_replacement()
	{
		long int n1,temp;
		int index;
		char ch;
		do
		{
			cout<<"Enter phone number:\n";
			cin>>n1;
			for(int i=0;i<max;i++)
			{
				if(n[i].phNo==n1)
				{
					cout<<"Sorry number's already added";
					break;
				}
				else{
					index=(n1%max);
			for(int i=0;i<max;i++)
			{
				if(n[index].phNo!=0)
				{
					temp=n[index].phNo;
					n[index].phNo=n1;
				}
				else
				{
					n[index].phNo=n1;
				}
			}
			for(int i=0;i<max;i++)
			{
				if(n[index].phNo==0)
				{
					n[index].phNo=temp;
				}
			}
				}
			}
			cout<<"\nDo you want to add more numbers(y/n):\n";
			cin>>ch;
			
		}while(ch!='n');
	}
	void display()
	{
		for(int i=0;i<max;i++)
		{
			cout<<"\n"<<n[i].phNo;
		}
	}
};

int main()
{
	hashTable h;
	char ch;
	int op;
	do
	{
		cout<<"\nMENU";
		cout<<"\n1.Without replacement";
		cout<<"\n2.With replacement";
		cout<<"\n3.Exit";
		cout<<"\nEnter your choice:";
		cin>>op;
		switch(op)
		{
			case 1:
				h.create_Hashtable();
				h.display();
				break;
			case 2:
				h.with_replacement();
				h.display();
				break;
				
		}
		
	}while(op!=3);
	
}
