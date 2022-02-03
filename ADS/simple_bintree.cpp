#include<iostream>
#define gspace 5
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	
	node(int value)
	{
		data=value;
		left=NULL;
		right=NULL;
	}
	void printbintree(node *root,int space)
	{
		if(root==NULL)
			return;
		space=gspace+space;
		printbintree(root->right,space);
		cout<<endl;
		for(int i=gspace;i<space;i++)
		{
			cout<<" ";
		}
		cout<<root->data<<endl;
		printbintree(root->left,space);
	}
};
int main()
{
	struct node *root;
//	root->left=new node(2);
//	root->right=new node(3);
		

	int ch,data;
	
	do
	{
	cout<<"MENU"<<endl;
	cout<<"1.Create a tree"<<endl;
	cout<<"2.Add a node"<<endl;
	cout<<"3.Print tree"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter your choice:"<<endl;
	cin>>ch;
	switch(ch)
	{	
		case 1:
			
			cout<<"Enter a root node:"<<endl;
			cin>>data;
			root=new node(data);
			cout<<"Tree created"<<endl;
			break;
		case 2:
			char pos;
			struct node* temp;
			cout<<"Enter a node to left of root:"<<endl;
			cin>>data;
			temp=new node(data);
			root->left=temp;
			cout<<"Node inserted"<<endl;
			cout<<"Enter a node to right of root:"<<endl;
			cin>>data;
			temp=new node(data);
			root->right=temp;
			char y;
			cout<<"Do you want to continue adding(y/n):"<<endl;
			cin>>y;
			if(y=='y')
			{
				cout<<"Enter a node to left of "<<root->left->data<<":"<<endl;
				cin>>data;
				temp=new node(data);
				root->left->left=temp;
				cout<<"Enter a node to right of "<<root->right->data<<":"<<endl;
				cin>>data;
				temp=new node(data);
				root->right->right=temp;
					
			}
			
			break;
		case 3:
			cout<<"Binary tree is:"<<endl;
			root->printbintree(root,5);
			break;
				
			
			
	}
}while(ch!=4);
	
	
}

