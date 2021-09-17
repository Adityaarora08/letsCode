#include<iostream>
using namespace std;
void merge(int arr[],int l,int h,int m)
{
	int arra[h-l];
	int k=0;
	int j=m+1;
	int i=l;
	while(i<=m&&j<=h)
	{    	
			if(arr[i]>=arr[j])
				arra[k++]=arr[j++];
			else
				arra[k++]=arr[i++];
	}
	while(i<=m)
	{
		arra[k++]=arr[i++];
	}
	while(j<=h)
	{
		arra[k++]=arr[j++];
	}
	for(int i=l;i<=h;i++)
	{
		arr[i]=arra[i];
	}
}
void mergesort(int arr[],int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,h);
		merge(arr,l,h,m);
		return;
	}
	
}

int main()
{
	int n;	
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<" ";
	}
	return 0;
}
