#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //{dist,node} 
        // priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it:adj[node]){
                int di = it.second;
                int wt = di + d;
                
                if(dist[it.first] > wt){
                    dist[it.first]=wt;
                    pq.push({wt,it.first});
                }
            }
        }
        
        return dist;
    }
};