#include<bits/stdc++.h>
using namespace std;

class Solution {    
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        for(int x=0;x<V;x++){
            if(indegree[x]==0)
                q.push(x);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto &it:adj[node]){
                indegree[it]--;
                
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return ans;
        
    }
};
