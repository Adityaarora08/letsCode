//problem: given vertex u, find shortest paths to all the vertices of the graph from u
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
const int N= 1e6+2;
const int INF = 1e9;
vector<bool> vis(N,0);
vector<pair<int,int> > adj[N];
vector<int> dist(N,INF);
void shortestDistance(int src,int n){
	dist[src]=0;
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()){
		pair<int,int> curr = pq.top();
		pq.pop();
		if(vis[curr.second]){
			continue;
		}
		vis[curr.second]=true;
		vector<pair<int,int> > neighbors = adj[curr.second];
        for(int i=0;i<neighbors.size();i++){
        	pair<int,int> chcurr = neighbors[i];
        	if(!vis[chcurr.first] && dist[chcurr.first]>(chcurr.second + dist[curr.first])){
        		dist[chcurr.first]=(chcurr.second + dist[curr.first]);
        		pq.push(make_pair(dist[chcurr.first],chcurr.first));
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
	shortestDistance(0,n);
	return 0;
}
