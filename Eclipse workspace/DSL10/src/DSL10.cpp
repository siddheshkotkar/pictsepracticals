#include<iostream>
using namespace std;
#include<stack>
class intopos
{
public:
	int prec(char c)
	{
		if(c=='^')
		{
			return 3;

		}
		else if(c=='/' || c=='*')
		{
			return 2;
		}
		else if(c=='+' || c=='-')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	string infixtopostfix(string s)
	{
		stack<char> st;
		string res;
		for(int i=0;i<s.length();i++)
		{
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			{
				res+=s[i];//directly add operand to result
			}
			else if(s[i]=='(')
			{
				st.push(s[i]);//directly push opening bracket in stack
			}
			else if(s[i]==')')
			{
				while(!st.empty() && st.top()!='(')
				{
					res+=st.top();//directly add elements other than ( in result
					st.pop();//pop those same from stack
				}
				if(!st.empty())
				{
					st.pop();//pop the reamining ( bracket...
				}
			}
			else
			{
				while(!st.empty() && prec(st.top())>=prec(s[i]))//check for operator precedance
				{
					res+=st.top();//if opeartor in stack is having greater precedance than current scanned operator then add the stack's operator to the result
					st.pop();//pop the stack's operator (the previous one)(which is greater) from the stack
				}
			}

		}
		while(!st.empty())
		{
			res+=st.top();//check if there are any elements in stack, if present then add them to result
			st.pop();//pop the same from stack
		}
		return res;//return the result...

	}

};
int main()
{
	intopos in;
	string expr;
	int ch;
	do{
		cout<<"\nMENU\n"<<"1.Convert expression\n"<<"2.Evaluate the expression:\n"<<"\n3.Exit\n"<<"Enter your choice:\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter expression:\n";
			cin>>expr;
			string result=in.infixtopostfix(expr);
			cout<<"\nPostfix expression is: "<<result;
			cout<<endl;
			break;
		case 2:
//			in.evaluate(expr);
			break;
		case 3:
			break;
		}
	}while(ch!=3);
}
