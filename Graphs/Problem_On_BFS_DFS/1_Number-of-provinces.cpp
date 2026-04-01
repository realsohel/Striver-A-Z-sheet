#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis) {
        vis[node] = 1;
        for(int j = 0; j < adj.size(); j++) {
            if(adj[node][j] == 1 && vis[j] == 0) {
                dfs(j, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};