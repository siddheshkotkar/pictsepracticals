#include<iostream>
using namespace std;
class person_additional_info
{

	string address,license;
	long int contact;
public:
	person_additional_info()
	{
		address="";
		license="";
		contact=000000000;

	}
	~ person_additional_info()
	{
//		cout<<"You are in destructor...";
	}
	friend class person;
};

class person
{
	string name,dob,blood_grp;
	int roll_no,division;
	float ht,wt;
	static int count;

	person_additional_info *pai;
public:
	person()
	{
		name="";
		dob="";
		blood_grp="";
		roll_no=0;
		division=1;
		ht=0;
		wt=0;
		pai=new person_additional_info();
	}

	person(person &p1)
	{
		name=p1.name;
		dob=p1.dob;
		blood_grp=p1.blood_grp;
		roll_no=p1.roll_no;
		division=p1.division;
		ht=p1.ht;
		wt=p1.wt;
		pai=new person_additional_info();
		pai->address=p1.pai->address;
		pai->contact=p1.pai->contact;
		pai->license=p1.pai->license;
	}

	~person()
	{
//		cout<<"Destructor for class person executed...";


	}
	inline void display();
	static void showcount()
	{
		cout<<count;
	}
	void getdata(string _name);

};

void person::getdata(string _name)
{
	name=_name;
	cout<<"Enter date of birth(ddmmyyyy):"<<endl;
	cin>>dob;
	cout<<"Enter blood group:"<<endl;
	cin>>blood_grp;
	cout<<"Enter roll no:"<<endl;
	cin>>roll_no;
	cout<<"Enter division:"<<endl;
	cin>>division;
	cout<<"Enter height:"<<endl;
	cin>>ht;
	cout<<"Enter weight:"<<endl;
	cin>>wt;
	cout<<"Enter address:"<<endl;
	cin>>pai->address;
	cout<<"Enter license:"<<endl;
	cin>>pai->license;
	cout<<"Enter contact number:"<<endl;
	cin>>pai->contact;
	count++;
}

void person::display()
{
	cout<<"\nName:"<<name;
	cout<<"\nDate of Birth:"<<dob;
	cout<<"\nBlood group:"<<blood_grp;
	cout<<"\nRoll no:"<<roll_no;
	cout<<"\nDivision:"<<division;
	cout<<"\nHeight:"<<ht;
	cout<<"\nWeight:"<<wt;
	cout<<"\nAddress:"<<pai->address;
	cout<<"\nContact:"<<pai->contact;
	cout<<"\nLicense:"<<pai->license<<endl;
}

int person::count=0;
int main()
{
	person *p1,*p2;
	p1=new person();
	p2=new person(*p1);
	int n,op,tp=0;
	string name;
	try
	{
	cout<<"Enter number of records you want to enter:";
	cin>>n;
	if(n<=0)
	{
		throw tp;
	}
	}
	catch(int tp)
	{
		cout<<"Please enter valid number of records!!";
		return 0;
	}

	person p3[n];
	bool getexit=false;
	while(getexit!=true)
	{

		cout<<"MENU:";
		cout<<"1.Enter the records:";
		cout<<endl<<"2.Display the records:";
		cout<<endl<<"3.Exit";
		cout<<endl<<"Enter your choice:";
		cin>>op;
		switch(op)
		{
		case 1:

			for(int i=0;i<n;i++)
			{
				cout<<"Enter name:"<<endl;
				cin>>name;
				p3[i].getdata(name);

			}
			break;

		case 2:

			for(int i=0;i<n;i++)
			{
				p3[i].display();
			}
			break;

		case 3:
			getexit=true;
		}
	}
	delete p1;
	delete p2;

	return 0;
}
