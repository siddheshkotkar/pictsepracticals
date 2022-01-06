#include<iostream>
using namespace std;
class publication
{
public:
	string title;
	float price;
	void enter_data()
	{
		cout<<"Enter title of the book:"<<endl;
		cin>>title;
		cout<<"Enter price of the book:"<<endl;
		cin>>price;
	}
};
class book:public publication
{
public:
	int page_count;
	void enter_cnt()
	{
		cout<<"Enter page count for "<<title<<" "<<endl;
		cin>>page_count;
	}
};
class tape:public publication
{
public:
	float minutes;
	void playing_time()
	{
		cout<<"Enter the "<<title<<" playing time:"<<endl;
		cin>>minutes;
	}
	void display()
	{
		cout<<"Title:"<<title<<endl;
		cout<<"Price:"<<price<<endl;
		cout<<"Playing minutes:"<<minutes<<endl;

	}
};

int main()
{
	int op,n;
	string c;
	cout<<"Enter number of records you want to enter:"<<endl;
	cin>>n;
	bool isexit=false;
	int i=0;
	tape t[n];
	book b[n];
	while(isexit!=true)
	{
	cout<<endl;
	cout<<"MENU"<<endl;
	cout<<"1.Enter record:"<<endl;
	cout<<"2.Display record:"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter your choice:"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			while(i<n)
			{
				t[i].enter_data();
				b[i].enter_cnt();
				t[i].playing_time();

				try
				{
					if(b[i].page_count<=0)
					{
						t[i].minutes=0;
						t[i].price=0;
						t[i].title="";
						b[i].page_count=0;
						throw c;
					}
					else if(t[i].minutes<=0)
					{
						t[i].minutes=0;
						t[i].price=0;
						t[i].title="";
						b[i].page_count=0;
						throw c;
					}
				}

				catch(string c)
				{
					cout<<"Exception catched!!"<<endl;

				}
				i++;
			}
			break;

		case 2:
			i=0;
			while(i<n)
			{
				t[i].display();
				cout<<"Page count:"<<b[i].page_count;
				i++;
			}
			break;
		case 3:
			isexit=true;
			break;
	}
}

}
