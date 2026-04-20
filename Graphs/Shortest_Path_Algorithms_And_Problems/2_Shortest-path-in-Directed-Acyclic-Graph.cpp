#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
public:
    // Using TOPO Sort + Relaxation.
    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int>&stk){
        vis[node]=1;
        
        for(auto &it:adj[node]){
            int nd = it.first;
            if(vis[nd]==0){
                dfs(nd,adj,vis,stk);
            }
        }
        stk.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt}); 
        }
        
        stack<int>stk;
        vector<int>vis(V,0);
        vector<int>dis(V,INT_MAX);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,stk);
            }
        }
        dis[0]=0;
        
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            int d = dis[node];
            
            if(dis[node] != INT_MAX) {  
                for(auto &it : adj[node]){
                    int f = it.first;
                    int wt = it.second;
                    dis[f] = min(dis[f], dis[node] + wt);
                }
            }
            
        }
        
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX)
                dis[i]=-1;
        }
        
        return dis;
    }
};
