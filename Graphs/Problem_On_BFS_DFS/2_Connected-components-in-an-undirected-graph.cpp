#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &temp) {
        vis[node] = 1;
        temp.push_back(node);
    
        for(auto it : adj[node]) {
            if(vis[it] == 0) {
                dfs(it, adj, vis, temp);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> vis(V, 0);
        vector<vector<int>> ans;
    
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                vector<int> temp;
                dfs(i, adj, vis, temp);
                ans.push_back(temp);
            }
        }
    
        return ans;
    }
};
