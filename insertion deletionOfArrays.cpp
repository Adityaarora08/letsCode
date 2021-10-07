#include<iostream>
using namespace std;
int main()
{
	int x,l,n,i,e;
	cout<<"Enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array: ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Menu:
	cout<<"\nPress 1 for insertion \nPress 2 for deletion\nPress 3 to print array\nPress 4 to exit"<<endl;
	cin>>x;
	switch(x)
	{
		case(1):
		cout<<"Enter location of element to be inserted: ";
		cin>>l;
		cout<<"Enter value of element to be inserted: ";
		cin>>e;
		for(i=n-1;i>=l;i--)
		{
			arr[i+1]=arr[i];
		}
		arr[l]=e;
		n=n+1;
		goto Menu;
		case(2):
		cout<<"Enter location of element to be deleted: ";
		cin>>l;
		for(i=l;i<n;i++)
		{
			arr[i]=arr[i+1];
		}
		n=n-1;
		goto Menu;
		case(3):
		cout<<"Array : ";
		for(i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		goto Menu;
		case(4):
			break;
	}
	return 0;
}
