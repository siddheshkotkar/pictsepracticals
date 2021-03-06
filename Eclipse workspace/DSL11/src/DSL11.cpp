#include<iostream>
using namespace std;
#define MAX 10
struct queue
{
	int front,rear;
	int data[MAX];
};
class queueop
{
public:
	struct queue q;
	queueop()
	{
		q.front=-1;
		q.rear=-1;

	}
	int isempty();
	int isfull();
	void enqueue(int x);
	int delqueue();
	void display();

};

int queueop::isempty(){

	return (q.front==-1)?1:0;
}

int queueop::isfull()
{

	return (q.rear==MAX-1)?1:0;
}

void queueop:: enqueue(int x)
{
	if(q.rear==-1)
	{
		q.front=0;
		q.rear=0;
		q.data[q.rear]=x;
	}

	else
	{
	q.data[++q.rear]=x;
	}
}

int queueop::delqueue()
{
	int popped=q.data[q.front];
	q.front++;
	return popped;

}
void queueop::display()
{   int i;
    cout<<"\n";
    for(i=q.front;i<=q.rear;i++)
	     cout<<q.data[i]<<" ";
}
int main()
{
	queueop qp;
	int ch;
	do
	{
		int element;
		cout<<"MENU"<<endl;
		cout<<"1.Insert job"<<endl;
		cout<<"2.Delete Job"<<endl;
		cout<<"3.Display jobs"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(qp.isfull()==1)
			{
				cout<<"Queue is full!!";
			}
			else
			{
				cout<<"Enter job to enter:"<<endl;
				cin>>element;
				qp.enqueue(element);
			}
			break;
		case 2:
			if(qp.isempty()==1)
			{
				cout<<"Queue is empty!!";
			}
			else
			{
				cout<<"deleted job is:"<<qp.delqueue()<<endl;
			}
			cout<<"Remaining jobs are:";
			qp.display();
			cout<<endl;
			break;
		case 3:
			qp.display();
			break;
		case 4:
			break;

		}
	}while(ch!=4);
}
