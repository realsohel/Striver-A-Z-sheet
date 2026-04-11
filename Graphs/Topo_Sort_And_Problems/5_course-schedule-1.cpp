#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        int cnt=0;
        
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            
            for(auto &it:adj[node]){
                indegree[it]--;
                
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(cnt==numCourses)return true;
        
        return false;

    }
};