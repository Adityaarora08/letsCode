#include<bits/stdc++.h>
using namespace std;
//for undirected graphs
bool isCycle(int src,vector<int> &adj[n],bool &vis[n],int parent){
	vis[src]=true;
	for(auto it: adj[src]){
		if(it!=parent){
			if(vis[it]){
				return true;
			}
			if(!vis[it] && isCycle(it,adj,vis,src)){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];
	bool vis[n];
	for(int i=0;i<n;i++){
		vis[i]=false;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]&& isCycle(i,adj,vis,-1)){
			return true;
		}
	}
	return false;
	
}
