#include<bits/stdc++.h>
using namespace std;
int findSubarraysWithSumK(int arr[],int k){
	int n=11;
	int prvSum[n];
	prvSum[0]=arr[0];
	for(int i=1;i<n;i++){
		prvSum[i]=prvSum[i-1]+arr[i];
	}
	unordered_map<int,int> mp;
	int ans=0;
	for(int i=0;i<n;i++){
		if(prvSum[i]==k){
			ans++;
		}
		if(mp.find(prvSum[i]-k)!=mp.end()){
			ans+= mp[prvSum[i]-k];
		}
		mp[prvSum[i]]++;
	}
	return ans;
}
int main(){
	int arr[]={6,3,-1,-3,4,-2,2,4,6,-12,-7};
	cout<<findSubarraysWithSumK(arr,0);
}
