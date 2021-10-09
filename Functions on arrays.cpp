#include<iostream>
using namespace std;
void input(int arr[],int n)
{
	cout<<"Enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++)
	cin>>arr[i];
}
void printarray(int arr[],int n)
{
	cout<<"The elements of the array are: "<<endl;
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
int sum(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	return sum;
}
int main()
{
	cout<<"Name: Aditya Arora\nUID: 20BCS3758"<<endl;
	cout<<"Enter size of array: ";
	int n;
	cin>>n;
	int arr[n];
	input(arr,n);
	cout<<"\nSum of elements of array: "<<sum(arr,n)<<endl;
	printarray(arr,n);
	return 0;
}
