#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Using BFS
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> ans(V,0);
        vis[src]=1;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            ans[node]=dis;
            
            for(auto &it:adj[node]){
                if(vis[it]==0){
                    q.push({it,dis+1});
                    vis[it]=1;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                ans[i]=-1;
            }
        }
        
        return ans;
    }
};
