#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+2;
vector<int> adj[N];
bool vis[N];
map<int,int> indeg;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		vis[i]=false;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		indeg[y]++;
	}
	queue<int> pq;
	for(int i=0;i<n;i++){
		if(indeg[i]==0){
			pq.push(i);
		}
	}
	int count=0;
	while(!pq.empty()){
		count++;
		int x= pq.front();
		pq.pop();
		cout<<x;
		for(auto it: adj[x]){
			indeg[it]--;
			if(indeg[it]==0){
				pq.push(it);
			}
		}
	}
	 if(count != n){
        cout<<"Graph is cyclic";
    }
    return 0;
} 
