#include<bits/stdc++.h>
using namespace std;
struct appnode
{
	int start;
	int end;
	int min;
	int max;
	int flag;
	struct appnode *next;
}*head;

class newclass
{
	public:
		void display_slots();
		void sched_app();
		void cancel_app();
		void sort_time();	
}n;

int main()
{
	cout<<"MENU";
	cout<<"1.Schedule an appointment"<<endl;
	cout<<"2.Display free slots"<<endl;
	cout<<"3.Cancel appointment"<<endl;
	cout<<"4.Sort list based on time"<<endl;
	cout<<"5.Sort list based on time using pointer manipulation"<<endl;
	cout<<"6.Exit"<<endl;
	int option;
	cout<<"Enter your option:"<<endl;
	cin>>option;
	while(option!=6)
	{
	
	switch(option)
	{
		case 1:
			n.sched_app();
			break;
		case 2:
			n.display_slots();
			break;
//		case 3:
//			n.cancel_app();
//			break;
//		case 4:
//			n.sort_time();
//			break;
//		case 5:
//			sort_time_pointer();
//			break;
		case 6:
			break;	
	}
}
}

void newclass :: display_slots()
{
	struct appnode *temp;
	cout<<"Start time\tEnd Time\tMin duration\t Max Duration \t Status"<<endl;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->start<<"\t";
		cout<<temp->end<<"\t";
		cout<<temp->min<<"\t";
		cout<<temp->max<<"\t";
		
		if(temp->flag)
		{
			cout<<"\tBooked";
		}
		else
		{
			cout<<"\tFree";
		}
		temp=temp->next;
		
	}
}

void newclass :: sched_app()           //Function Definition to create Appointment Schedule
{
    int i,size;
    struct appnode *temp, *last;
    
    head = NULL;
    
    cout<<"\n\n\t How many Appointment Slots: ";
    cin>>size;
    
    for(i=0; i<size; i++)
    {
       temp = new(struct appnode);         // Step 1: Dynamic Memory Allocation
       
       cout<<"\n\n\t Enter Start Time: ";   // Step 2: Assign Data & Address
       cin>>temp->start; 
       cout<<"\n\t Enter End Time: ";
       cin>>temp->end;
       cout<<"\n\n\t Enter Minimum Duration: ";
       cin>>temp->min;
       cout<<"\n\t Enter Maximum Duration: ";
       cin>>temp->max;
       temp->flag = 0;
       temp->next = NULL;
       
       if(head == NULL)
       {
          head = temp;
          last = head;
       }
       else
       {
          last->next = temp;
          last = last->next;
       }
       
    }
}
