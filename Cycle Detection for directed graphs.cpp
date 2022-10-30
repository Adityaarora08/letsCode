#include<bits/stdc++.h>
using namespace std;
//for directed graphs
bool isCycle(int src,vector<int> &adj[n],vector<bool> &vis[n],vector<bool> stack[n]){
	stack[src]=true;
	if(!vis[src]){
		vis[src]=true;
		for(auto it: adj[src]){
			if(!visited[it] && isCycle(it,adj,vis,stack)){
				return true;
			}
			if(stack[it]){
				return true;
			}
		}
	}
	stack[src]=false;
	return false;
}
int main(){
	int n,m;
	bool cycle=false;
	cin>>n>>m;
	vector<int> adj[n];
	vector<bool> vis(n,0);
	vector<bool> stack(n,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]&& isCycle(i,adj,vis,stack)){
			cycle= true;
		}
	}
	if(cycle){
		cout<<"Cycle is present";
	}
	
}
