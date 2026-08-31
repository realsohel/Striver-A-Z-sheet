#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e:edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        // {wt, {node, parent}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        
        vector<int> vis(V,0);
        vector<pair<int,int>> MST;
        int sum =0;
        
        pq.push({0, {0,-1}});
        
        // E 
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;

            // Log E
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            sum+= wt;
            MST.push_back({node,parent});
            
            // E
            for(auto &it:adj[node]){
                int nd = it.first;
                int w = it.second;
                
                if(!vis[nd]){
                    // Log E
                    pq.push({w, {nd,node}});
                }
                
            }
            
        }
        
        return sum;
    }
};