#include <bits/stdc++.h> 
using namespace std;

class DisjointSet{
public:
    vector<int> rank, parent,size;

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
    int removeStones(vector<vector<int>>& stones) {
        int V = stones.size();
        int mxR =0, mxC=0;

        unordered_map<int,int> stoneNodes;

        for(auto &it:stones){
            mxR=max(mxR,it[0]);
            mxC=max(mxC,it[1]);
        }

        DisjointSet ds(mxR+mxC+1);
        for(auto &it:stones){
            int row = it[0];
            int col = it[1] + mxR + 1;
            ds.unionBySize(row,col);
            stoneNodes[row]=1;
            stoneNodes[col]=1;
        }

        int cnt=0;
        for(auto &it:stoneNodes){
            if(ds.findUParent(it.first)== it.first)
                cnt++;
        }

        return V - cnt;
    }
};