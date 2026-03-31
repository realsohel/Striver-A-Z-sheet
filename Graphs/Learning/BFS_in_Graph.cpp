#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> vis(adj.size(),0);
        queue<int>q;
        vis[0]=1;
        q.push(0);
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};