#include<bits/stdc++.h>
using namespace std;
class dictionary;
class Node
{
	
	string word,meaning;
	Node *left,*right;
	
public:
	friend class dictionary;	
	Node()
	{
		left=NULL;
		right=NULL;
	}
	
	Node(string word,string meaning)
	{
		this->word=word;
		this->meaning=meaning;
		left=NULL;
		right=NULL;
	}
	
};
class dictionary
{
	
	Node *root;
public:	
	dictionary()
	{
		root=NULL;
	}
	void create();
	bool insert(string,string);
	void inorder(Node *);
	int nofcomp(string);	
	void doinorder()
	{
		inorder(root);
	}
	void descending()
	{
		inorder_desc(root);
	}
	void inorder_desc(Node *);
	Node *deletekeyword(Node *,string);
	Node *inorderSuccessor(Node *root)
	{
		Node *current=root;
		while(current && current->left!=NULL)
		{
			current=current->left;
		}
		return current;
	}
	void performDelete(string keyword)
	{
		deletekeyword(root,keyword);
	}
   	void performUpdate(string replacemeaning)
   	{
   		updateKeyword(root,replacemeaning);
	   }
	void updateKeyword(Node *,string);
};

void dictionary::updateKeyword(Node *root,string replacemeaning)
{
	string replace;
	if(root->word==replacemeaning)
	{
		cout<<endl<<"Enter the meaning of word:";
		cin>>replace;
		root->meaning=replace;
	}
	else if(replacemeaning>root->word)
	{
		updateKeyword(root,replacemeaning);
	}
	else if(replacemeaning<root->word)
	{
		updateKeyword(root,replacemeaning);
	}
}

Node *dictionary::deletekeyword(Node *root,string keyword)
{
	if(keyword<root->word)
	{
		root->left=deletekeyword(root->left,keyword);
	}
	else if(keyword>root->word)
	{
		root->right=deletekeyword(root->right,keyword);
	}
	else
	{
		if(root->left==NULL)
		{
			Node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			Node *temp=root->left;
			free(root);
			return temp;
		}
		
		Node *temp=inorderSuccessor(root->right);
		root->word=temp->word;
		root->right=deletekeyword(root->right,temp->word);
	}
	return root;
}
void dictionary::inorder_desc(Node *root)
{
	if(root)
	{
		inorder_desc(root->right);
		cout<<root->word<<" : "<<root->meaning<<endl;
		inorder_desc(root->left);
	}
}
void dictionary::create()
	{
		int n;
		string inp_word,inp_meaning;
		char ch='y';
		while(ch!='n')
		{
		
		cout<<"Enter number of words you want to enter in dictionary: ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<endl<<"Enter "<<i+1<<" th word:";
			cin>>inp_word;
			cout<<endl<<"Enter "<<inp_word<<"'s meaning:";
			cin>>inp_meaning;
			insert(inp_word,inp_meaning);
		}
		
		cout<<"Do you want to enter more elements in the dictionary (y/n) ?: ";
		cin>>ch;
		
	}
   }
   
   bool dictionary:: insert(string word,string meaning)
   {
   	Node *newnode=new Node(word,meaning);
   	if(root==NULL)
   	{
   		root=newnode;
   		return true;
	}
   	Node *tpc=root;
   	Node *current=root;
   	while(current!=NULL)
   	{
   		if(word>current->word)
   		{
   			tpc=current;
   			current=current->right;	
		}
		else if(word<current->word)
		{
			tpc=current;
			current=current->left;
		}
		else
		{
			cout<<endl<<"Word is already present in the dictionary!!";
		}
	   }
	if(word>tpc->word)
	{
		
		tpc->right=newnode;
		return true;
	   }
	   
	   else if(word<tpc->word)
	   {
	   	tpc->left=newnode;
	   	return true;
		}
		   
   }
   void dictionary:: inorder(Node *root)
   {
   	if(root)
   	{
   		inorder(root->left);
   		cout<<root->word<<" : "<<root->meaning<<endl;
   		inorder(root->right);
	   }
   }
   
			   
   
   int dictionary:: nofcomp(string key)
   {
   		Node *temp=root;
   		int count;
   		if(temp==NULL)
   		{
   			return -1;
		}
		if(root->word==key)
		{
			return 1;
		}
		while(temp!=NULL)
		{
			if(temp->word>key)
			{
				temp=temp->left;
				count++;
			}
			else if(temp->word<key)
			{
				temp=temp->right;
				count++;
			}
			else if(temp->word==key)
			{
				return ++count;
			}
		}
		return -1;
   }
   
   

int main()
{
	int ch;
	dictionary d;
	do
	{
	
	cout<<"\n1.Enter elements in dictionary";
	cout<<"\n2.Print the ascending order:";
	cout<<"\n3.Print the descending order:";
	cout<<"\n4.Search a word and find the number of comparisons required";
	cout<<"\n5.Update a word's meaning";
	cout<<"\n6.Delete a word";
	cout<<"\n7.Exit";
	cout<<"\nEnter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			d.create();
			break;
		case 2:
			cout<<"Ascending order is:"<<endl;
			d.doinorder();
			break;
		case 3:
			cout<<"Descending order is:"<<endl;
			d.descending();
			break;
		case 4:
			{
			
			string search;
			cout<<"Enter a word to be searched:";
			cin>>search;
			int x=d.nofcomp(search);
			cout<<"No of comparisons are "<<x;
			break;
			}
		case 5:
			{
			string replacemeaning;
			cout<<endl<<"Enter the word to replace its meaning:";
			cin>>replacemeaning;
			d.performUpdate(replacemeaning);
			cout<<endl<<"Inorder traversal after updation:"<<endl;
			d.doinorder();
			break;
		    }
			
		case 6:
			string deleteword;
			cout<<endl<<"Enter a word to be deleted:";
			cin>>deleteword;
			d.performDelete(deleteword);
			cout<<endl<<"Inorder traversal after deletion:"<<endl;
			d.doinorder();
			break;
	}
	
	
	

}while(ch!=7);
}
