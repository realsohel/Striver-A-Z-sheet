#include <bits/stdc++.h> 
using namespace std;
// solved by me
class Solution {
public:
    int solve(int row, int col,int m,int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(row==m) return 0;
        if(col==n) return 0;

        if(obstacleGrid[row][col]==1)
            return 0;
        
        if(row==m-1 and col==n-1) 
            return 1;
        
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int right = solve(row,col+1,m,n, obstacleGrid, dp);
        int down = solve(row+1,col,m,n, obstacleGrid, dp);

        return dp[row][col]=(right+down);
    }
    
    int tabulation(int m,int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        dp[0][0]=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) 
                    continue;

                if(i==0 and j==0) {
                    dp[0][0]=1;
                    continue;
                }

                int left=0, up=0;
                if(i>0)
                    left = dp[i-1][j];
                if(j>0)
                    up = dp[i][j-1];
                
                dp[i][j] = left+up;
            }
        }

        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(0,0,m,n,obstacleGrid, dp);
        return tabulation(m,n,obstacleGrid, dp);
    }
};