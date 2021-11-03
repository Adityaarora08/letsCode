#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void sort(int *arr,int n)
{
	for(int j=0;j<n;j++)
	{
	int b=j;
	int mini=INT_MAX;
	for(int i=j;i<n;i++)
	{
		if(mini>arr[i])
		{
			mini = arr[i];
			b=i;
		}
	}
	swap(arr[b],arr[j]);
	}
}
int main()
{
	int arr[]={9,5,7,1,3,2};
	int n = 6;
    sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
		
		}	
	return 0;
}
