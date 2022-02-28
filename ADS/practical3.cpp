#include<bits/stdc++.h>
using namespace std;
struct node
{
	public:
		int data;
		node *left,*right;
		bool isthread;
};

class bintree
{
public:
	node *root=NULL;
	
	void insertElement(int ele){
        node *temp = root;
        char direction;
        
        if(temp == NULL){
            root = new node;
            root->data = ele;
            root->left = NULL;
            root->right = NULL;
            cout<<"\nElement added to root";
            return;
        }
        cout<<"\nInsert To the l/r? :";
        cin>>direction;
        bool isDest = false;
        while(!isDest) {
            if(direction == 'r') {
                if(temp->right == NULL) {
                    isDest = true;
                    continue;
                }
                temp = temp->right;
                cout<<"\nInsert at l/r of "<<temp->data<<"?";
                cin>>direction;
            }
            else if(direction == 'l') {
                if(temp->left == NULL) {
                    isDest = true;
                    continue;
                }
                temp = temp->left;
                cout<<"\nInsert at l/r of "<<temp->data<<"?";
                cin>>direction;
            }
            else{
                cout<<"\nDuplicate Element!!!";
                return;
            }
        }
        struct node *newEle = new node;
        newEle->data = ele;
        newEle->left = NULL;
        newEle->right = NULL;
         if(direction == 'r') {
            temp->right = newEle;
        }
        else{
            temp->left = newEle;
        }
       
        
}
	node *createThreaded(node *root)
	{
		if(root==NULL)
			return NULL;
		
		if(root->left==NULL && root->right==NULL)
			return root;
		
		if(root->left!=NULL)
		{
			node *tnode=createThreaded(root->left);
			
			tnode->right=root;
			tnode->isthread=true;
		}
		
		if(root->right==NULL)
			return root;
		
		return createThreaded(root->right);
		
	}
	node *leftmost(node *root)
	{
		while(root!=NULL && root->left!=NULL)
		{
			root=root->left;
		}
		return root;
	}
	
	void inorderPrint(node *root)
	{
		node *temp=leftmost(root);
		while(temp!=NULL)
		{
			cout<<temp->data<<"\n";
			
			if(temp->isthread)
				temp=temp->right;
			
			else
				temp=leftmost(temp->right);
		}
	}
	void createThreaded_inorderTraversal()
	{
		createThreaded(root);
		inorderPrint(root);
	}
    };
    
int main()
{
	bintree b;
	int n,x;
	cout<<endl<<"Enter number of nodes you want to enter:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"Enter "<<i+1<<" th node:";
		cin>>x;
		b.insertElement(x);
	}
	cout<<"\nThreaded tree created...\n";
	b.createThreaded_inorderTraversal();
	
}
