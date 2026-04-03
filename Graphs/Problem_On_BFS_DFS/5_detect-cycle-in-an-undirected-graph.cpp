#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 2. Using DFS
    bool dfs(int src,int parent,  vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(vis[it] == 0) {
                if(dfs(it,src, adj, vis))
                    return true;
            }
            else if(parent!=it){
                return true;
            }
        }

        return false;
    }

    // 1. Using BFS
    bool bfs(int src, vector<vector<int>> &adj, vector<int> &vis){
        queue<pair<int,int>>q;
        vis[src]=1;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int p = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(p!=it){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){ // vis[i]==0
                // if(bfs(i,adj,vis))
                //     return true;
                
                if(dfs(i,-1,adj,vis))return true;
            }
        }
        return false;
    }
};