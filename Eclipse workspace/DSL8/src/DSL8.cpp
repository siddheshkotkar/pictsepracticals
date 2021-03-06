#include<iostream>
#include<string.h>
using namespace std;
struct node {
	string name;
	bool butterscotch,vanilla;
	struct node *next;
};
class linkedlistmanager
{
public:
	struct node *head=NULL;
	void addelements(string stud_name,bool vanilla,bool butterscotch)
	{

		struct node *element=head;
		if(head==NULL)
		{
			head = new node;
			head->name=stud_name;
			head->butterscotch=butterscotch;
			head->vanilla=vanilla;
			head->next=NULL;
			return;
		}

		while(element->next!=NULL)
		{
			element=element->next;
		}

		struct node *temp=new node;
		temp->name=stud_name;
		temp->butterscotch=butterscotch;
		temp->vanilla=vanilla;
		temp->next=NULL;
		element->next=temp;


	}

	void printelements()
	{
		node *temp=head;
		cout<<"Data in Linked list is:"<<endl;
		if(head==NULL)
		{
			cout<<"List is empty";
		}

		while(temp!=NULL)
		{
			cout<<"Name:"<<temp->name<<endl;
			if(temp->vanilla)
			{
				cout<<temp->name<<" likes vanilla icecream"<<endl;
			}
			if(temp->butterscotch)
			{
				cout<<temp->name<<" likes butterscotch icecream"<<endl;
			}
			temp=temp->next;
		}
	}

	void printchoice(string filter)
	{
		node *temp=head;
		if(head==NULL)
		{
			cout<<"List is empty"<<endl;
		}
		while(temp!=NULL)
		{
			if(filter=="both")
			{
				if(temp->butterscotch==1 && temp->vanilla==1)
				{
					cout<<temp->name<<" likes both butterscotch and vanilla"<<endl;
				}
			}
			else if(filter=="either")
			{


				if(temp->vanilla==1 || temp->butterscotch==1 || temp->vanilla==0 || temp->butterscotch==0)
				{

					if(temp->vanilla)
					{
						cout<<temp->name<<"likes vanilla"<<endl;
					}
					else if(temp->butterscotch)
					{
						cout<<temp->name<<" likes butterscotch"<<endl;
					}
					if(!temp->vanilla && !temp->butterscotch)
					{
						cout<<temp->name<<" doesnt like any of the icecream"<<endl;
					}
				}
			}
			else if(filter=="neither")
			{
				if(temp->vanilla==0 && temp->butterscotch==0)
				{
					cout<<temp->name<<" doesnt like any of the icecream"<<endl;
				}
			}
			temp=temp->next;
		}
	}



};
int main()
{
	linkedlistmanager llm;
	int n;
	int ch;
	string name;
	char butterscotch,vanilla;
	bool tempvan=false,tempbutter=false;
	cout<<"Enter the number of students you want to enter:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		tempvan=0, tempbutter = 0;
		cout<<"\nEnter name of student"<<endl;
		cin>>name;
		cout<<"Does "<<name<<" likes vanilla(y/n):"<<endl;
		cin>>vanilla;
		tempvan = vanilla == 'y';
		cout<<"Does "<<name<<" likes Butterscotch(y/n):"<<endl;
		cin>>butterscotch;
		tempbutter = butterscotch == 'y';
		llm.addelements(name, tempvan,tempbutter);

	}
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1.Print the list"<<endl;
		cout<<"2.Get students who like both vanilla and butterscotch"<<endl;
		cout<<"3.Get students who like either vanilla or butterscotch or none"<<endl;
		cout<<"4.Get students who like neither vanilla nor butterscotch"<<endl;
		cout<<"5.Exit"<<endl;

		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			llm.printelements();
			break;
		case 2:
			llm.printchoice("both");
			break;
		case 3:
			llm.printchoice("either");
			break;
		case 4:
			llm.printchoice("neither");
			break;
		case 5:
			break;
		}
	}while(ch!=5);
}
