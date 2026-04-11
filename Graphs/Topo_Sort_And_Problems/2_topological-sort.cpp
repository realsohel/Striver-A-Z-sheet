#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int>&stk){
        vis[node]=1;
        
        for(auto &it:adj[node]){
            if(vis[it]==0){
                dfs(it,adj,vis,stk);
            }
        }
        stk.push(node);
    }
    
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        stack<int>stk;
        vector<int>vis(V,0);
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,stk);
            }
        }
        
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
        
    }
};
