#include<bits/stdc++.h>
using namespace std;
class employee
{
	public:
		int empid;
		string empname;
		char bey[5]="n";
		
		int input();
		int best_employee();
};

int employee::input()
{
	employee e;
	ofstream of;
	of.open("Employee.txt");
	if(!of)
	{
		cout<<"Failed to create File"<<endl;
	}
	else
	{
		int n=0;
		cout<<"Enter number of employees to enter:";
		cin>>n;
		cout<<endl;
		for(int i=0;i<n;i++)
		{
		
		cout<<"Enter emp id:";
		cin>>e.empid;
		cout<<endl<<"Enter emp name:";
		cin>>e.empname;
		cout<<endl<<"Best employee(y/n):";
		cin>>e.bey;
	    
		of.write((char*)&e,sizeof(e));
	    }
	}
	of.close();
	return 0;
	
}

int employee::best_employee()
{
	employee e;
	int bestemp=0;
	string name;
	ifstream fi;
	fi.open("Employee.txt",ios::in);
	fi.read((char*)&e,sizeof(e));
	while(!fi.eof())
	{
		if(e.bey=="y")
		{
			bestemp=1;
			name=e.empname;
			
		}
		fi.read((char*)&e,sizeof(e));
	}
	
	cout<<name;
	fi.close();
	
	return 0;
}

int main()
{
	employee e;
	e.input();
	e.best_employee();
	return 0;
}
