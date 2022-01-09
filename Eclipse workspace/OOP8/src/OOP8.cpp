#include<iostream>
using namespace std;
template <class  T>
T selection_sort()
{
	int n,min;
	cout<<"Enter the number of elements you want to enter:"<<endl;
	cin>>n;
	T arr[n],temp;
	cout<<"Please enter "<<n<<" elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];

	}
	for(int i=0;i<n;i++)
	 {
		min=i;
	     for(int j=i+1;j<n;j++)
	          {
	              if(arr[j]<arr[min])
	                {
	            	  	 min=j;
	                }
	            }
	     temp=arr[i];
	     arr[i]=arr[min];
	     arr[min]=temp;
	         }

	cout<<"Sorted array is:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}

}

int main()
{

	int op;
	do
	{
		cout<<endl;
		cout<<"MENU"<<endl;
		cout<<"1.Integer sorting"<<endl;
		cout<<"2.Float sorting"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>op;
		switch(op)
		{
		case 1:
			selection_sort<int> ();
			break;
		case 2:
			selection_sort<float> ();
			break;
		case 3:
			break;



		}
	}while(op!=3);

}
