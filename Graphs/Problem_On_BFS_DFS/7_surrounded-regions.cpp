#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();
        if(vis[r][c]==1){
            return;
        }    
        
        vis[r][c]=1;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= r+drow[i];
            int ncol= c+dcol[i];
            
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and board[nrow][ncol]=='O' and vis[nrow][ncol]==0)
            dfs(nrow,ncol,board,vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
        }

        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
        
    }
};