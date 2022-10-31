#include<bits/stdc++.h>
using namespace std;
int getComp(int idx,vector<int> &adj,vector<bool> &vis){
	if(vis[idx]){
		return 0;
	}
	vis[idx]=true;
	int ans=1;
	for(auto it : adj[idx]){
		if(!vis[it]){
			ans+=getComp(it,adj,vis);
			vis[it]=true;
		}
	}
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<bool> vis(n,0);
	vector<int> adj[n];
	vector<int> componentsSizes;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			componentsSizes.push_back(getComp(i,adj,vis));
		}
	}
	cout<<"Number of components : "<<componentsSizes.size();
}
