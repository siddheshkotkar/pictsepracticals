#include<bits/stdc++.h>
using namespace std;
template <typename T>
void sort(T arr[],int n)
{
	int min;
	int temp;
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
	int n;
	cout<<"int operation:"<<endl;
	cout<<"Enter number of elements you want to enter:"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,n);
	
	cout<<"Float operation:"<<endl;
	
	int n1;
	cout<<"Enter number of float elements you want to enter:";
	cin>>n1;
	float arr1[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	sort(arr1,n);
}


int n;
	cout<<"Enter the number of elements you want to enter:"<<endl;
	cin>>n;
