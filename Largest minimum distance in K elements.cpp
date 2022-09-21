#include<bits/stdc++.h>
using namespace std;
bool isFeasible(int mid,int arr[],int n,int k){
	int pos=arr[0],elements=1;
	for(int i=1;i<n;i++){
		if(arr[i]-pos>=mid){
			pos=arr[i];
			elements++;
			if(elements==k){
				return true;
			}
		}
	}
	return false;
}
int largestMinDistance(int arr[],int n,int k){
	int result=INT_MIN;
	int left=1,right=arr[n-1];
	int mid;
	sort(arr,arr+n);
	while(left<right){
		mid=(left+right)/2;
		if(isFeasible(mid,arr,n,k)){
			left=mid+1;
			result=max(result,mid);
		}else{
			right=mid;
		}
	}
	return result;
}
int main(){
	int arr[]={5,1,4,9,11};
	cout<<largestMinDistance(arr,5,3);
}
