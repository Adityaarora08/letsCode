#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
	parent[v]=v;
	sz[v]=1
}
int find_set(int v){
	if(parent[v]==v){
		return v;
	}
	return parent[v]=find_set(parent[v]);
}
void make_union(int a,int b){
	a= find_set(a);
	b= find_set(b);
	if(a!=b){
		if(sz[a]>sz[b])swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > edges;
	for(int i=0;i<n;i++){
		make_set(i);
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>w>>u>>v;
		vector<int> dummy;
		dummy.push_back(w);
		dummy.push_back(u);
		dummy.push_back(v);
		edges.push_back(dummy);
	}
	sort(edges.begin(),edges.end());
	int totalWeight=0;
	for(int i=0;i<edges.size();i++){
		int w= find_set(edges[i][0]);
		int x= find_set(edges[i][1]);
		int y= find_set(edges[i][2]);
		if(x==y){
			continue;
		}else{
			make_union(x,y);
			totalWeight+=w;
		}
	}
	cout<<"Total weight of spanning tree : "<<totalWeight<<endl;
}
