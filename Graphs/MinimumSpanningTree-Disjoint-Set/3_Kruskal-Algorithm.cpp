#include <bits/stdc++.h> 
using namespace std;

class DisjointSet{

    vector<int> rank, parent,size;
public:

    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node==parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};



class Solution {
  public:
    
    // Krushkal's Algo
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<pair<int,pair<int,int>>> adj(V);
        
        // {wt, {node, node}}
        for(auto &e:edges){
            adj.push_back({e[2], {e[0], e[1] }});
        }
        
        sort(adj.begin(), adj.end());
        
        int ans=0;
        DisjointSet ds(V);
        
        for(auto &it:adj){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
        
            if(ds.findUParent(u)!= ds.findUParent(v)){
                ans+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return ans;
    }
    
};