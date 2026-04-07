#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// Same as previous question but eliminated vis array. 

    void dfs(int r,int c,vector<vector<int>>& grid){
        int n = grid.size();
        int m= grid[0].size();

        if(grid[r][c]==2) return;

        grid[r][c]=2;

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= r+drow[i];
            int ncol= c+dcol[i];

            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    cnt++;
            }
        }

        return cnt;

    }
};