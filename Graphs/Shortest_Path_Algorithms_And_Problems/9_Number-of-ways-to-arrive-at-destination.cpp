#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &x : roads){
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            auto [time, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if(time > dist[node]) continue;

            for(auto &it : adj[node]){

                int next = it.first;
                long long newDist = time + it.second;

                // Found shorter path
                if(dist[next] > newDist){

                    dist[next] = newDist;
                    ways[next] = ways[node];

                    pq.push({newDist, next});
                }

                // Found another shortest path
                else if(dist[next] == newDist){

                    ways[next] = (ways[next] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};