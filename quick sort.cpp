#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int s,int e){
	int count=0;
	for(int i=s+1;i<=e;i++)
	{
		if(arr[s]>arr[i])
		{
			count++;
		}
	}
	swap(arr[count+s],arr[s]);
	int i=s,j=e;
	while(i<count+s||j>count+s)
	{
		if(arr[i]<arr[count+s])
			i++;
		else if(arr[j]>arr[count+s])
			j--;
		else
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	return (count+s);
}
void quicksort(int arr[],int s,int e){
	if(s<e){
		int p=partition(arr,s,e);
		quicksort(arr,s,p);
		quicksort(arr,p+1,e);
		return;
	}
	else
	return;
}
int main(){
	int n;
	cout<<"enter the no of array elements: ";
	cin>>n;
	int arr[n];
	cout<<"enter the array elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
