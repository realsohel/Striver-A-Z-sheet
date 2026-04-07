#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        
        if(vis[node]==1 && pathVis[node]==1) return true;
        
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(dfs(it,adj,vis,pathVis)) return true;
        }
        pathVis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj, vis,pathVis)) return true;
            }
        }
        
        return false;
    }
};