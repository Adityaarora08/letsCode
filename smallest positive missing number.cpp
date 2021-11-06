#include<iostream>
using namespace std;
int main()
{
	int arr[]={3,-5,1,5,-9,7,0};
	int n=7;
	bool check[n];
	for(int i=0;i<n;i++)
	{
		check[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=0)
		   check[arr[i]]=true;
	}
	for(int i=0;i<n;i++)
	{
		if(check[i]==false)
		  {
		  	cout<<i;
		  	break;
		  }
	}
	return 0;
}
