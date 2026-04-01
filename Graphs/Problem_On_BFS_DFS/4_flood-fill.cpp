#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        
        int og = grid[sr][sc];
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        grid[sr][sc]=newColor; 
        vis[sr][sc]=1;
        int drow[] = {-1, 0, 1,0};
        int dcol[] = {0, 1, 0,-1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and 
                    ncol<m and vis[nrow][ncol]!=1 and grid[nrow][ncol]==og){
                    grid[nrow][ncol]=newColor; 
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
            
        }
        
        return grid;
        
    }
};