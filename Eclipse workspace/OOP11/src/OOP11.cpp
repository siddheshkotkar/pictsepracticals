#include<iostream>
#include<vector>
#include<algorithm> //for sort function
using namespace std; // make all the things under this scope as namespace std so no need of std:: prefix
class elements
{
public:
	string name,telephone,db;
	int _id;
};
bool comparebyID(elements a,elements b)
{
	return a._id<b._id;
}
bool comparebyname(elements a,elements b)
{
	return a.name[0]<b.name[0];
}
class personalrecord
{
public:
	vector<elements> pd;

	void input(int n)
	{
		int cid=1;
		for(int i=0;i<n;i++)
		{
			elements e;
			cout<<"Name:";
			cin>>e.name;
			cout<<"\nTelephone:";
			cin>>e.telephone;
			cout<<"\ndate of birth:";
			cin>>e.db;
			e._id=cid;
			cid++;
			pd.push_back(e);
		}
	}

	void displayrecords()
	{
		vector<elements>::iterator i=pd.begin();
		while(i!=pd.end())
		{
			cout<<"\nName:"<<i->name;
			cout<<"\nTelephone:"<<i->telephone;
			cout<<"\nDate of birth:"<<i->db;
			cout<<"\nID:"<<i->_id;
			i++;
		}
	}

	void searchbyid(int id)
	{
		vector<elements>::iterator i=pd.begin();
		while(i!=pd.end())
		{
			if(i->_id==id)
			{
				cout<<"\nName:"<<i->name;
				cout<<"\nTelephone:"<<i->telephone;
				cout<<"\nDate of birth:"<<i->db;
				cout<<"\nID:"<<i->_id;
				return;
			}
			i++;
		}
		cout<<"\nrecord not found";
	}

	void returnsort(string str)
	{
		if(str=="id")
		{
			sort(pd.begin(),pd.end(),comparebyID);//sending refernece of comparebyID
		}
		if(str=="name")
		{
			sort(pd.begin(),pd.end(),comparebyname);
		}
	}





};

int main()
{
	personalrecord pr;
	bool isexit=false;
	int op,n;
	cout<<"Enter number of records you want to enter:"<<endl;
	cin>>n;
	pr.input(n);

	while(isexit!=true)
	{
		cout<<"\nMENU"<<endl;
		cout<<"1.Display all records"<<endl;
		cout<<"2.Search record by ID"<<endl;
		cout<<"3.Sort records by id"<<endl;
		cout<<"4.Sort records by name"<<endl;
		cout<<"enter your choice:"<<endl;
		cin>>op;
		switch(op)
		{
		case 1:
			pr.displayrecords();
			break;
		case 2:
			int id;
			cout<<"\nEnter id to search:";
			cin>>id;
			pr.searchbyid(id);
			break;
		case 3:
			pr.returnsort("id");
			break;
		case 4:
			pr.returnsort("name");
			break;
		case 5:
			isexit=true;
			break;
		}
	}
}
