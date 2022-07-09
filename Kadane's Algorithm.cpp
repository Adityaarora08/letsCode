#include<iostream>
using namespace std;
int kadane(int arr[],int n)
{
	int start_sum=INT_MIN;
	int current_sum=0;
	for(int i=0;i<n;i++)
	{
		current_sum+=arr[i];
		if(start_sum<current_sum)
		start_sum=current_sum;
		if(current_sum<0)
		current_sum=0;
	}
}
