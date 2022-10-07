#include<bits/stdc++.h>
using namespace std;
int sizeOfSubsequence(int arr[],int k){
	priority_queue<int, vector<int> > pq;
	int n=5;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	int count=0,sum=0;
	while(!pq.empty()){
		sum+=pq.top();
		pq.pop();
		count++;
		if(sum>=k){
			return count;
		}
	}
	return -1;
}
int main(){
	//smallest subsequrnce of sum >=k
	int arr[]={3,5,1,6,2};
	int k=10;
	cout<<sizeOfSubsequence(arr,k);
	return 0;
}
