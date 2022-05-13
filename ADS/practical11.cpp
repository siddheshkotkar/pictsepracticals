#include<bits/stdc++.h>
using namespace std;
class heap
{
    public:
        void insert(int a[],int n,int value)
        {  
            a[n]=value;
            
            int i=n;
            while(i>1)
            {
                int parent=i/2;
                if(a[parent]<a[i])
                {
                    swap(a[parent],a[i]);
                    i=parent;
                }
                else
                {
                    return;
                }
            }
        }
};
int main()
{
    heap h;
    int n;
    cout<<"\n Enter N:";
    cin>>n;
    int heap_arr[n],x;
    cout<<"\n Enter elements:";
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(i==1)
            {heap_arr[i]=x;
            continue;}
        h.insert(heap_arr,i,x);
        
    }
    cout<<"\n array is:";
    for(int i=1;i<=n;i++)
    {
        cout<<heap_arr[i]<<"\t";
    }
}