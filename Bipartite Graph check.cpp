// C++ program to check if a connected
// graph is bipartite or not using DFS
#include <bits/stdc++.h>
using namespace std;

// function to store the connected nodes
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// function to check whether a graph is bipartite or not
bool isBipartite(vector<int> adj[], int v,
				vector<bool>& visited, vector<int>& color)
{

	for (int u : adj[v]) {

		// if vertex u is not explored before
		if (visited[u] == false) {

			// mark present vertices as visited
			visited[u] = true;

			// mark its color opposite to its parent
			color[u] = !color[v];

			// if the subtree rooted at vertex v is not bipartite
			if (!isBipartite(adj, u, visited, color))
				return false;
		}

		// if two adjacent are colored with same color then
		// the graph is not bipartite
		else if (color[u] == color[v])
			return false;
	}
	return true;
}

// Driver Code
int main()
{
	// no of nodes
	int N = 6;

	// to maintain the adjacency list of graph
	vector<int> adj[N + 1];

	// to keep a check on whether
	// a node is discovered or not
	vector<bool> visited(N + 1);

	// to color the vertices
	// of graph with 2 color
	vector<int> color(N + 1);

	// adding edges to the graph
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);
	addEdge(adj, 5, 6);
	addEdge(adj, 6, 1);

	// marking the source node as visited
	visited[1] = true;

	// marking the source node with a color
	color[1] = 0;

	// Function to check if the graph
	// is Bipartite or not
	if (isBipartite(adj, 1, visited, color)) {
		cout << "Graph is Bipartite";
	}
	else {
		cout << "Graph is not Bipartite";
	}

	return 0;
}
















//#include<bits/stdc++.h>
//using namespace std;
//// 1 for red
//// 2 for blue
//bool color(int src,vector<int> &adj,vector<bool> &vis,vector<int> &colors,int parent){
//	vis[src]=true;
//	if(parent==1){
//		colors[src]=2;
//	}else{
//		colors[src]=1;
//	}
//	vector<int> :: iterator it;
//	for(it=adj[src].begin();it!=adj[src].end();it++){
//		if(colors[*it]!=0){
//			if(colors[*it]!=parent){
//				return false;
//			}
//		}else{
//			color[*it]=parent;
//			if(!color(it,adj,vis,colors,colors[src])){
//				return false;
//			}
//		}
//	}
//	return true;
//}
//int main(){
//	int n,m;
//	cin>>n>>m;
//	vector<bool> vis(n,0);
//	vector<int> adj[n];
//	vector<int> colors(n,0);
//	for(int i=0;i<m;i++){
//		int u,v;
//		cin>>u>>v;
//		adj[u].push_back(v);
//		adj[v].push_back(u);
//	}
//	bool ans =true;
//	for(int i=0;i<n;i++){
//		if(!vis[i]){
//			if(!color(i,adj,vis,colors,2)){
//				ans= false;
//			}
//		}
//	}
//	cout<<ans;
//}
