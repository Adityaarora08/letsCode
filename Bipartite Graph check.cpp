// C++ program to check if a connected
// graph is bipartite or not using BFS and dfs

class Solution {
public:
    // DFS code
    vector<int>vis,col;
    bool dfs(int v, int c, vector<vector<int>>& graph){
        vis[v]=1;
        col[v]=c;
        for(int child:graph[v]){
            if(vis[child]==0){
                // here c^1 is for flipping 1 by 0 or 0 by 1, that is flip the current color
                if(dfs(child,c^1,graph)==false) 
                    return false;
            }
            else{
                if(col[v]==col[child])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);

        for(int i=0;i<n;++i){
            if(vis[i]==0 && dfs(i,0,graph)==false){ 
                return false;
            }
        }
        
        return true;
    }
    //dfs code end
    // bool colorNode(int src,int parent,vector<vector<int>>& graph,vector<bool> &vis,vector<int> &colors){
    //     if(!vis[src]){
    //         vis[src]=true;
    //         if(colors[parent]== 1){
    //             colors[src]= 2;
    //         }else if(colors[parent]== 2){
    //             colors[src]= 1;
    //         }
    //     }
    //     if(colors[parent]==colors[src]){
    //             return false;
    //         }
    //     return true;
    // }
    // bool bipartite(vector<vector<int> >& graph,vector<int>& colors,vector<bool>& vis,int v){
    //     for(int i=0;i<graph[v].size();i++){
    //         if(!vis[graph[v][i]]){
    //             vis[graph[v][i]]=true;
    //             colors[graph[v][i]]= !colors[v];
    //             if(!bipartite(graph,colors,vis,graph[v][i])){
    //                 return false;
    //             }
    //         }else if(colors[graph[v][i]]==colors[v]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // bool isBipartite(vector<vector<int>>& graph) {
        // vector<bool> vis(graph.size(),0);
    
    //Correct code with bfs
//         int n = graph.size();
//         vector<int> colors(n, 0);
//         queue<int> q;
        
//         for (int i = 0; i < n; i++) {
//             if (colors[i]) continue;
            
//             colors[i] = 1;
//             q.push(i);
            
//             while (!q.empty()) {
//                 int temp = q.front();
                
//                 for (auto neighbor : graph[temp]) {
                    
// 					// Color neighbor with opposite color
//                     if (!colors[neighbor]){
//                         colors[neighbor] = -colors[temp];
//                         q.push(neighbor);
//                     }
                    
// 					// If the neighbor has the same color - can't bipartite.
//                     else if (colors[neighbor] == colors[temp]) 
//                         return false;
//                 }
//                 q.pop();
//             }
//         }
//         return true;
        //bfs code end
    
    
        // vector<int> colors(graph.size(),0);
        // queue<int> q;
        // for(int i=0;i<graph.size();i++){
        //     if(colors[i])continue;
        //     colors[i]=1;
        //     q.push(i);
        //     while(!q.empty()){
        //         int temp = q.front();
        //         for(int it : graph[temp]){
        //             if(!colors[it]){
        //                 q.push(it);
        //                 colors[it]=-colors[temp];
        //             }else if(colors[it]==colors[temp]){
        //                 return false;
        //             }
        //         }
        //         q.pop();
        //     }
        // }
        // return true;
        
        
        
        
        
        
        
   //Wrong code 79/81 test cases passed     
	// vis[0]=1;
	// colors.push_back(0);
	// if (bipartite(graph,colors,vis,0)) {
	// 	return true;
	// }
	// else {
	// 	return false;
	// }
        // for(int i=0;i<graph.size();i++){
        //     if(!vis[i]){
        //         for(int j=0;j<graph[i].size();j++){
        //             if(vis[graph[i][j]]){
        //                 if(colors[graph[i][j]]== 1){
        //                     colors[i]= 2;
        //                 }else if(colors[graph[i][j]]== 2){
        //                     colors[i]= 1;
        //                 }
        //             }
        //         }
        //         if(colors[i]==0){
        //             colors[i]=1;
        //         }
        //         vis[i]=true;
        //         for(int j=0;j<graph[i].size();j++){
        //             if(colorNode(graph[i][j],i,graph,vis,colors)==false){
        //                 return false;
        //             }
        //         }
        //     }else{
        //         for(int j=0;j<graph[i].size();j++){
        //             if(colorNode(graph[i][j],i,graph,vis,colors)==false){
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;
    // }
};










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
