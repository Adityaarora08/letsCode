#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr,int last,int first){
	int maxIdx=first;
	int l=2*first+1,r=2*first+2;
	if(l<last && arr[l]>arr[maxIdx])
	maxIdx=l;
	if(r<last && arr[r]>arr[maxIdx])
	maxIdx=r;
	if(maxIdx!=first){
		swap(arr[first],arr[maxIdx]);
		heapify(arr,last,maxIdx);
	}
}
void heapSort(vector<int> &arr){
	int n=arr.size();
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
int main(){
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(7);
	int n=arr.size();
	heapSort(arr);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
