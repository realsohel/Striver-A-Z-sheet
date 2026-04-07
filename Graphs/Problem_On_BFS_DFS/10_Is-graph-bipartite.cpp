#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// 1. DFS
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& color) {
        for (auto it : graph[src]) {
            if (color[it] == -1) {
                color[it] = 1 - color[src]; 
                if (!dfs(it, graph, color)) {
                    return false;
                }
            }
            else if (color[it] == color[src]) {
                return false;
            }
        }
        return true;
    }

    
// 1. BFS
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[node]; 
                    q.push(it);
                }
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};