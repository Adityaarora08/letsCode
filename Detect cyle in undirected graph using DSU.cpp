#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
	parent[v]=v;
	sz[v]=1;
}
int find_parent(int v){
	if(parent[v]==v){
		return v;
	}
	return parent[v]=find_parent(parent[v]);
}
void union_sets(int a,int b){
	a= find_parent(a);
	b= find_parent(b); 
	if(a!=b){
		if(sz[a]>sz[b])
		   swap(a,b);
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
		int u,v;
		cin>>u>>v;
		vector<int> dummy;
		dummy.push_back(u);
		dummy.push_back(v);
		edges.push_back(dummy);
	}
	bool cycle=false;
	for(int i=0;i<edges.size();i++){
		int x= find_parent(edges[i][0]);
		int y= find_parent(edges[i][1]);
		if(x==y){
			cycle=true;
		}else{
			union_sets(edges[i][0],edges[i][1]);
		}
	}
	if(cycle==true){
		cout<<"Cycle present"<<endl;
	}else{
		cout<<"Cycle not present"<<endl;
	}
}

