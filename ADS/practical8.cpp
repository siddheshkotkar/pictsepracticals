#define MAX 50
#include <iostream>
#include<vector>
using namespace std;
class stack
{
	public:
		int data[MAX];
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
		void push(int x)
		{
			top++;
			data[top]=x;
		}
		void pop()
		{
			int x=data[top];
			top--;
		}
		
};
class Solution {
  void findTopoSort(int node, vector < int > & vis, stack & st, vector < int > adj[]) {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);
  }
  public:
    vector < int > topoSort(int N, vector < int > adj[]) {
      stack st;
      vector < int > vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.data[st.top]);
        st.pop();
      }
      return topo;

    }
};

int main() {
  int N ;
cout<<"\n Enter number of nodes:";
cin>>N;
  char direc;
    int v[N];
    for(int i=0;i<N;i++)
            {
                cout<<"\n Enter node:";
                cin>>v[i];
            }
  vector < int > adj[N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<"\n Is "<<v[i]<<" to "<<v[j]<<" a connection(y/n):";
                    cin>>direc;
                    if(direc=='y')
                    {
                        
                        adj[i].push_back(j);
                    }
                    
        }
    }


  Solution obj;
  vector < int > res = obj.topoSort(6, adj);

  cout << "Topological sort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 