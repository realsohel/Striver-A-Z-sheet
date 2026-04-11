#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathVis, vector<int> &chks){

        vis[node]=1;
        pathVis[node]=1;

        for(auto &it:adj[node]){
            if(vis[it]==0){
                if(dfs(it, adj,vis,pathVis,chks))
                    return true;
            }
            else if(pathVis[it]==1)
                return true;
        }

        chks[node]=1;
        pathVis[node]=0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V,0), pathVis(V,0), chks(V,0);
        vector<int> safe;

        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,pathVis,chks);
            }
        }

        for(int i=0;i<V;i++){
            if(chks[i]==1)
                safe.push_back(i);
        }

        return safe;
    }
};