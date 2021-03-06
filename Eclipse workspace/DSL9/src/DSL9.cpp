#include<iostream>
//#include<stack>
using namespace std;
class stack
{
public:
	int top=-1;
	char str[20];
	bool isempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	bool isfull()
	{
		if(top==20-1)
			return 1;
		else
			return 0;
	}
	void push(char c)
	{
		if(!isfull())
		{
		top++;
		str[top]=c;
		}
	}
	char pop()
	{
		if(!isempty())
		{
			char ch=str[top];
			top--;
			return ch;
		}
		else
		{
			return '\0';
		}
	}


};
class checkvalid
{
public:
	stack st;
	bool isvalid(string s)
	{
		int n=s.size();
		bool answer=true;

		for(int i=0;i<n;i++)
		{
			if(s[i]=='(' || s[i]=='[' || s[i]=='{')
			{
				st.push(s[i]);
			}
			else if(s[i]==')')
			{
				if(!st.isempty()  && st.str[st.top]=='(')
				{
					st.pop();
				}
				else
				{
					answer=false;
					break;
				}
			}
			else if(!st.isempty() &&  s[i]==']')
						{
							if( st.str[st.top]=='[')
							{
								st.pop();
							}
							else
							{
								answer=false;
								break;
							}
						}
			else if(!st.isempty() && s[i]=='}')
						{
							if( st.str[st.top]=='{')
							{
								st.pop();
							}
							else
							{
								answer=false;
								break;
							}
						}


		}
		if(!st.isempty())
		{
			return false;
		}
		return answer;
	}
};
int main()
{
	checkvalid c;
	string expr;

	int ch;
	bool ans;
	do
	{
		cout<<"\nMENU";
		cout<<"\n1.Check expression";
		cout<<"\n2.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter expression:";
			cin>>expr;
			ans=c.isvalid(expr);
			if(ans==true)
			{
				cout<<"String is well parenthesized!";
			}
			else
			{
				cout<<"String is not well paranthesized!";
			}
			break;
		case 2:
			break;
		}
	}while(ch!=2);
}
