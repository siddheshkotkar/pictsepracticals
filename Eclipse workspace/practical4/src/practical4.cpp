#include<iostream>
#include<fstream>
//#include<string.h>
using namespace std;
class operation
{
public:
	ifstream fin;
	ofstream of;
	void create_write()
	{
		 of.open("sample.txt",ios::app);
		if(!of)
		{
			cout<<"Failed to create file!!";
		}
		else
		{
			string s;
			cout<<"Enter string to be inputted: ";
//			cin.clear();//to clear the console's input
			cin.ignore(INT_MAX,'\n');//ignore the input till max integer and also the new line
			getline(cin,s);//reading from standard input

			cout<<"The line is "<<s<<endl;
			of<<endl;
			of<<s;

		}
		of.close();
	}

	void read()
	{
		fin.open("sample.txt");
		string s;
		while(getline(fin,s))//extracting from fin i.e file
		{
			cout<<s;
			cout<<endl;
		}
		fin.close();
	}



};
int main()
{
	operation op;
	int op1;

	bool isexit=false;
	while(isexit!=true)
	{
	cout<<endl;
	cout<<"MENU"<<endl;
	cout<<"1.Create a file and write into it"<<endl;
	cout<<"2.Read the file"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>op1;
	switch(op1)
	{
	case 1:
		op.create_write();
		break;
	case 2:
		op.read();
		break;
	case 3:
		isexit=true;
		break;
	}
	}
	}
