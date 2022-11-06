//problem: given vertex u, find shortest paths to all the vertices of the graph from u
// we can also find negative weight cycle using this algorithm because if the nth iteration is done and the values of dist is still
// decreasing then there is negative cycle present
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
const int N= 1e6+2;
const int INF = 1e9;
vector<bool> vis(N,0);
vector<pair<int,int> > adj[N];
vector<int> dist(N,INF);

void shortestDistance(int src,int n,int m){
	dist[src]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<adj[j].size();k++){
				int src= j;
				int dest = adj[j][k].first;
				int weight= adj[j][k].second;
				if(dist[src] != INF && dist[src]+weight < dist[dest]){
					dist[dest]= dist[src]+weight;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
			cout<<i<<" - "<<dist[i]<<endl;
		}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	shortestDistance(0,n,m);
	return 0;
}
