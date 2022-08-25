#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={1,2,3,4,5,6,7,8};
	int n=8;
	int k=3;
	deque<int> q;
	vector<int> ans;
	for(int i=0;i<k;i++){
		while(!q.empty() && arr[q.back()]<arr[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	ans.push_back(arr[q.front()]);
	for(int i=k;i<n;i++){
		if(q.front()==i-k){
			q.pop_front();
		}
		while(!q.empty() && arr[q.back()]<arr[i]){
			q.pop_back();
		}
		q.push_back(i);
    	ans.push_back(arr[q.front()]);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
