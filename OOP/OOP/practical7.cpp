#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class fileoperations
{
	public:
		ofstream of1;
		ifstream if1;
		void createfile()
		{
		of1.open("sample.txt");
			if(!of1)
			{
				cout<<"Error in creating file...";
			}
				
		}
		
		void writefile()
		{
			
			string str;
			cin>>str;
			of1<<str<<endl;
			of1.close();
		}
		
		void accessfile()
		{
			
			
	
			if1.open("sample.txt");
			string temp;
			if1>>temp;
			cout<<temp<<endl;
			if1.close();
		}
			
};
int main()
{
	fileoperations f1;
	int option;
	cout<<"MENU"<<endl;
	while(option!=4)
	{
	
	cout<<"1.Create a file:"<<endl;
	cout<<"2.Write in the file:"<<endl;
	cout<<"3.Access the file:"<<endl;
	cout<<"4.Exit"<<endl;
	
	cin>>option;
	
	
	switch(option)
	{
		case 1:
			f1.createfile();
		break;
		case 2:
			
				f1.writefile();
				break;
				
		case 3:
			f1.accessfile();
			break;
			
	}
	
}
	
}
