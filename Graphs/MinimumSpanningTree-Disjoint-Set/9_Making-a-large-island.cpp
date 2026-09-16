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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        // 1. Connect Components
        for(int row=0;row<n;row++){
            for(int col=0;col<n; col++){

                if(grid[row][col]==0) continue;
                int dr[]={-1, 0, 1, 0};
                int dc[]={0, 1, 0, -1};

                for(int i=0;i<4;i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];

                    if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc] == 1 ){
                        int currNode = row*n + col;
                        int newNode = newr*n + newc;

                        ds.unionBySize(currNode, newNode);
                    }
                }
            }
        }

        // 2. Try Converting 0's
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n; col++){
                if(grid[row][col]==1) continue;

                int dr[]={-1, 0, 1, 0};
                int dc[]={0, 1, 0, -1};
                set<int> components;

                for(int i=0;i<4;i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];

                    if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc]==1){
                        components.insert(ds.findUParent(newr * n + newc));
                    }
                }

                int szTot=0;

                for(auto &it:components){
                    szTot += ds.size[it];
                }

                maxi = max(maxi,szTot+1);
            }
        }

        // Case for All 1's

        for(int cell=0; cell<n*n; cell++){
            maxi = max(maxi, ds.size[ds.findUParent(cell)] );
        }

        return maxi;
    }
};