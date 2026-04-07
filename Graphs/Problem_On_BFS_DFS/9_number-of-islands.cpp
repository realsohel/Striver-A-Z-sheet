#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// APPROACH 2 --> Better Approach
    void dfs(int r, int c, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0') return;

        grid[r][c] = '0'; // mark visited

        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r+1, c, grid);
        dfs(r, c-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }


// APPROACH 1
    void dfs(int r,int c,vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m= grid[0].size();

        if(vis[r][c])return;
        vis[r][c]=1;

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= r+drow[i];
            int ncol= c+dcol[i];

            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and vis[nrow][ncol]==0){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==0){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return cnt;
    }
};