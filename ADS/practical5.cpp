//============================================================================
// Name        : practical5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define MAX 10
using namespace std;
class node
{
public:
	string key,value;
	node *next;

	node()
	{
		key="",value="";
		next=NULL;
	}
};
class dictionary:public node
{
public:
	string word,meaning;
	node *n = new node[MAX];

	void init()
	{
		for(int i=0;i<MAX;i++)
		{
			n[i] = new node;
		}
	}
	void accept()
	{
		int index,len;
		char ch;
		do{
		cout<<"\n Enter Word:";
		cin>>word;
		cout<<"\n Enter its meaning:";
		cin>>meaning;
		len=word.length();
//		cout<<len<<"\n";
		index=(len%MAX);
//		cout<<index;
		if(n[index].key=="")
		{
			n[index].key=word;
			n[index].value=meaning;

		}
		else if(n[index].key!="")
		{
			node *head = &n[index];
			node *newnode=new node();
			while(head->next!=NULL)
			{
				head = head->next;
			}

			newnode->key=word;
			newnode->value=meaning;
			head->next=newnode;
		}
		cout<<"\n Do you want to enter more(y/n):";
		cin>>ch;
		}while(ch!='n');
	}
	int find(string fkey)
	{
		int ind,flen;
		flen=fkey.length();
		ind=(flen%MAX);
		while(n[ind].key!=""){
			if(n[ind].key==fkey)
			{
				return ind;
			}

		}
		return 0;
	}
	void display()
	{
		for(int i=0;i<MAX;i++)
		{

			if(n[i].next!=NULL)
			{
				cout<<"\n"<<n[i].key;
				cout<<"\t -> \t"<<n[i].next->key;
				cout<<"\n"<<n[i].value;
				cout<<"\t\t"<<n[i].next->value;

			}
			else
			{
				cout<<"\n no collision";
			}
		}
	}
};
int main()
{
	dictionary d;
	d.accept();
	d.display();
	string find;
	cout<<"Enter string to find:";
	cin>>find;
	int x=d.find(find);
	if(x!=0)
	{
		cout<<"\n String found at index "<<x;
	}
}
