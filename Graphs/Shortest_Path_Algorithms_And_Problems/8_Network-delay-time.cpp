#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &x:times){
            adj[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;

            pq.pop();
            if(d > dist[node]) continue;

            for(auto &it:adj[node]){
                int di = it.second;
                int wt = di + d;

                if(dist[it.first] > wt){
                    dist[it.first]=wt;
                    pq.push({wt,it.first});
                }
            }
        }

        dist[0]=0;
        int maxi = *max_element(dist.begin(),dist.end());

        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};