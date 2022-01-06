#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
class mapp
{
public:
	string state;
	int population;
	void inputstates(int n,map<string,int> temp)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Enter state"<<endl;
			cin>>state;
			cout<<"Enter "<<state<<" population:"<<endl;
			cin>>population;
			temp.insert(pair<string,int> (state,population));

		}

	map<string,int>::iterator i=temp.begin();
	while(i!=temp.end())
	{
		cout<<"State:"<<i->first<<endl;
		cout<<"population:"<<i->second<<endl;
		i++;
	}

	}

	void returnpopulation(map<string,int> temp,string findstate)
			{
				string st=findstate;

				if(temp.find(st)==temp.end())
				{
					cout<<st<<"  not found"<<endl;
				}
				else
				{
					cout<<st<<" has a population of "<<temp.find(st)->second;
				}

			}


};
int main()
{
	map <string,int> m1;
	mapp m;
	int op;
	bool isexit=false;
	string searchstate;
	while(isexit!=true)
	{
		cout<<endl<<"MENU:"<<endl;
			cout<<"1.Input States:"<<endl;
			cout<<"2.Find Population:"<<endl;
			cout<<"Enter your choice:"<<endl;
			cin>>op;
			switch(op)
			{
			case 1:
				int n;
				cout<<"Enter number of states:";
				cin>>n;
				m.inputstates(n,m1);
				break;

			case 2:
				cout<<"Enter state to get its population:"<<endl;
				cin>>searchstate;
				m.returnpopulation(m1,searchstate);
				break;

			case 3:
				isexit=true;
				break;
			}
	}
}
