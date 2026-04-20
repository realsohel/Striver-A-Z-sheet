#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        set<pair<int,int>> st;  // {dist, node}
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto &nbr : adj[node]){
                int v = nbr.first;
                int wt = nbr.second;
                
                if(dist[v] > d + wt){
                    if(dist[v] != INT_MAX){
                        st.erase({dist[v], v});
                    }
                    
                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};