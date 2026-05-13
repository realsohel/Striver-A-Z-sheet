#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        // {stops, {node,dis}}
        queue< pair<int, pair<int,int>> > q;
        vector<int>  dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int d = q.front().second.second;
            q.pop();
            if(stop>k) continue;

            for(auto &it:adj[node]){
                int di = it.second;
                int wt = di + d;
                
                if(dist[it.first] > wt and stop<=k){
                    dist[it.first]=wt;
                    q.push({stop+1,{it.first,wt}});
                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }



    int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:flights){
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({v,w});
        }

        // {dist,{node,stops}}
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        pq.push({0,{src,0}});
        dist[src][0]=0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second.first;
            int stop = pq.top().second.second;
            pq.pop();

            if(node==dst){
                return d;
            }
            if(stop>k) continue;
            for(auto &it:adj[node]){
                int di = it.second;
                int wt = di + d;
                
                if(dist[it.first][stop+1] > wt){
                    dist[it.first][stop+1]=wt;
                    pq.push({wt,{it.first,stop+1}});
                }
            }

        }

        return -1;
    }
};