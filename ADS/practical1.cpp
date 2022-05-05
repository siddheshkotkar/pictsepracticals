#include <iostream>
#define MAX 50
using namespace std;

struct Node {
    Node *left, *right;
    int data;
};
class stack
{
	public:
		Node* data[MAX];
		int top=-1;
	public:
		bool empty()
		{
			if(top==-1)
			{
				return true;
			}
			return false;
		}
		void push(Node *x)
		{
			top++;
			data[top]=x;
		}
		void pop()
		{
			Node *x=data[top];
			top--;
		}
		
};
class queue
{
	public:
		Node *data[MAX];
		int rear=-1,front=-1;
	public:
		bool empty()
		{
			if(front==-1)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}
		
		void push(Node *x)
		{
			if(front==-1)
			{
				rear++;
				front=0;
				data[rear]=x;
			}
			else
			{
				rear++;
				data[rear]=x;
			}
		}
		
		void pop()
		{
			if(front==rear)
			{
				
				front=-1;
				rear=-1;
			}
			else
			{
				
				front++;
			}
		}
			
};
class BinaryTree {
    public:
    Node *root = NULL;


    void insertElement(int ele){
        Node *temp = root;
        char direction;
        cout<<"\nInsert To the l/r? :";
        cin>>direction;
        if(temp == NULL){
            root = new Node;
            root->data = ele;
            root->left = NULL;
            root->right = NULL;
            cout<<"\nElement added to root";
            return;
        }
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
        struct Node *newEle = new Node;
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

    void recursiveInorderPrint(Node *current) {
        if(current == NULL) return;
        recursiveInorderPrint(current->left);
        cout<<"\n"<<current->data;
        recursiveInorderPrint(current->right);
    }

    void recursivePreorderPrint(Node *current) {
        if(current == NULL) return;
        cout<<"\n"<<current->data;
        recursivePreorderPrint(current->left);
        recursivePreorderPrint(current->right);
    }

    void recursivePostorderPrint(Node *current) {
        if(current == NULL) return;
        recursivePostorderPrint(current->left);
        recursivePostorderPrint(current->right);
        cout<<"\n"<<current->data;
    }

    void iterativeInorderPrint() {
        stack s;
        Node *current = new Node();
        current=root;

        while(current != NULL || !s.empty()){
            while(current != NULL) {
                s.push(current);
                current = current->left;
            }

            current = s.data[s.top];
            s.pop();
            cout<<"\n"<<current->data;
            current = current->right;
        }
    }

    void iterativePreorderPrint() {
        stack s;
        Node *current = root;

        while(current != NULL || !s.empty()){
            while(current != NULL) {
                cout<<"\n"<<current->data;
                if(current->right){
                    s.push(current->right);
                }
                current = current->left;
            }
            if(!s.empty()){
                current = s.data[s.top];
                s.pop();
            }
        }
    }

    void iterativePostorderPrint() {
        stack s1, s2;
        Node *current = root;
        s1.push(current);
        while(!s1.empty()) {
            current = s1.data[s1.top];
            s1.pop();
            s2.push(current);
            if(current->left) {
                s1.push(current->left);
            }
            if(current->right) {
                s1.push(current->right);
            }
        }
        while(!s2.empty())
        {
        	current = s2.data[s2.top];
        	s2.pop();
        	cout<<"\n"<<current->data;
		}
    }
    
    void change_pointers(Node *rootnode)
    {
    	if(rootnode==NULL)
    	{
    		return;
		}
		else
		{
			Node *temp;
			change_pointers(rootnode->left);
			change_pointers(rootnode->right);
			
			temp=rootnode->left;
			rootnode->left=rootnode->right;
			rootnode->right=temp;
			
		}
	}
	
	int ret_height(Node *rootnode)
	{
		if(rootnode==NULL)
			return 0;
		int x=ret_height(rootnode->left);
		int y=ret_height(rootnode->right);
		return(max(x,y)+1);
		
	}
	
	BinaryTree operator=(BinaryTree &tree)
	{

		Node *current=tree.root;
		BinaryTree newTree;
		newTree.root=new Node;
		newTree.root->data=current->data;
		copytreeElements(current,newTree.root);
		return newTree;
	}
	
	void copytreeElements(Node *current,Node *newtreeCurrent)
	{
		
		if(!current->left && !current->right)
			return;
		if(current->left)
		{
			newtreeCurrent->left=new Node;
			newtreeCurrent->left->data=current->left->data;
			copytreeElements(current->left,newtreeCurrent->left);
		}
		if(current->right)
		{
			newtreeCurrent->right=new Node;
			newtreeCurrent->right->data=current->right->data;
			copytreeElements(current->right,newtreeCurrent->right);
		}
		
	}
	
	void createNewCopy()
	{
		BinaryTree &newBT=*this;
		cout<<endl<<"new copy created...";
		cout<<endl<<"Inorder traversal of new tree elements is:"<<endl;;
		newBT.recursiveInorderPrint(newBT.root);
	}
	
	int getleafcount(Node *root)
	{
		int x,y;
		if(root==NULL)
			return 0;
		if(root->left==NULL && root->right==NULL)
			return 1;
		else
			x=getleafcount(root->left);
			y=getleafcount(root->right);
			return x+y;
	}
	
	void printInternal(Node *root)
	{
		queue  q;
		q.push(root);
		
		int count=0;
		
		while(!q.empty())
		{
			Node *currentNode=q.data[q.front];
			q.pop();
			bool isInternalNode=0;
			if(currentNode->left!=NULL)
			{
				isInternalNode=1;
				q.push(currentNode->left);
			}
			if(currentNode->right!=NULL)
			{
				isInternalNode=1;
				q.push(currentNode->right);
			}
			if(isInternalNode==1)
			{
				count=count+1;
			}
		}
		cout<<endl<<"Number of Internal Nodes are: "<<count<<endl;
	}
	void deletetree(Node *node)
	{
		if(node==NULL)
			return;
		deletetree(node->left);
		deletetree(node->right);
		cout<<"Deleted node is: "<<node->data<<endl;
		// Sleep(1200);
		
		delete node;
	}

    void printMenu(){
    	cout<<"\n***************Binary Tree Operations***************";
        cout<<"\n----------------------MENU----------------------";
        cout<<"\n1. Add Element to the tree";
        cout<<"\n2. Perform Recursive Inorder Traversal";
        cout<<"\n3. Perform Recursive Preorder Traversal";
        cout<<"\n4. Perform Recursive Postorder Traversal";
        cout<<"\n5. Perform Iterative Inorder Traversal";
        cout<<"\n6. Perform Iterative Preorder Traversal";
        cout<<"\n7. Perform Iterative Postorder Traversal";
        cout<<"\n8. Exchange Node pointers";
        cout<<"\n9. Get Height of the tree";
        cout<<"\n10. Copy contents of tree";
        cout<<"\n11. Print Leaf node count and Internal node count";
        cout<<"\n12. Delete the tree";
        cout<<"\n13. Exit";
        
        
    }

    void exec() {
        cout<<"\nEnter number of elements you want to insert initially: ";
        int n;
        cin>>n;
        for(int i = 0; i < n; i++) {
            cout<<"\nEnter "<<i+1<<"th element: ";
            int ele;
            cin>>ele;
            insertElement(ele);
        }
        bool isExit = false;
        while(!isExit) {
            printMenu();
            cout<<"\nEnter your choice: ";
            int ch;
            cin>>ch;
            switch(ch) {
                case 1:
				{
                    cout<<"\nEnter element: ";
                    int ele;
                    cin>>ele;
                    insertElement(ele);
                    cout<<"\nElement "<<ele<<" inserted successfully!!";
                    break;
                }
                case 2:
                    recursiveInorderPrint(root);
                    break;
                case 3:
                    recursivePreorderPrint(root);
                    break;
                case 4:
                    recursivePostorderPrint(root);
                    break;
                case 5:
                    iterativeInorderPrint();
					break;
				case 6:
					iterativePreorderPrint();
					break;
				case 7:
					iterativePostorderPrint();
					break;	
                case 8:
                    change_pointers(root);
                    cout<<endl<<"Inorder traversal of the mirror tree is as follows:";
                    recursiveInorderPrint(root);
                    break;
                case 9:
                {
				
					int z=ret_height(root);
                	cout<<"\n Height of the tree is "<<z;
                	break;
                }
                case 10:
                	createNewCopy();
					break;
				case 11:
					{
						int temp=getleafcount(root);
						cout<<endl<<"The leaf count of binary tree is: "<<temp<<endl;
						printInternal(root);
						break;
					}
				case 12:
					deletetree(root);
					cout<<"Tree deleted..."<<endl;
					break;
				case 13:
					isExit=true;
					break;
                    	
            }
        }
    }
};

int main() {
    BinaryTree bt;
    bt.exec();
    return 0;
}


















