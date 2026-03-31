#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int node,vector<vector<int>>& adj, vector<int> &vis, vector<int>&ans){
        if(vis[node]==1){
            return;
        }    
        
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it:adj[node]){
            solve(it,adj,vis,ans);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),0);
        vector<int> ans;
        solve(0,adj,vis,ans);
        return ans;
    }
};