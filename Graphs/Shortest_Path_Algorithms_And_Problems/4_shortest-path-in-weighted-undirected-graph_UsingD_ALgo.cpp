#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int dis = it.first;
            int node = it.second;
            
            for(auto &nbr : adj[node]){
                int v = nbr.first;
                int wt = nbr.second;
                
                if(dist[v] > dis + wt){
                    dist[v] = dis + wt;
                    parent[v] = node;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        path.insert(path.begin(), dist[n]);
        
        return path;
    }
};