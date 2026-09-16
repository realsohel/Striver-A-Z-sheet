#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stk){
        
        vis[node]=1;
        
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it, vis,adj,stk);
            }
        }
        
        stk.push(node);
    }
    
    void dfsA(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfsA(it, vis,adj);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        stack<int> stk;
        vector<int> vis(V,0);
        
        for(int i=0;i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, stk);
            }
        }
        
        vector<vector<int>> adjT(V);
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            
            for(auto &it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            
            if(!vis[node]){
                scc++;
                dfsA(node, vis, adjT);
            }
        }
        
        return scc;
    }
};