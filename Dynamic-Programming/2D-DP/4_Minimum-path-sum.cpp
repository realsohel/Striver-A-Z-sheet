#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int solve(int row,int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row>=m || col>=n)
            return INT_MAX;
        
        if(row==m-1 and col==n-1)
            return grid[row][col];
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int down = solve(row+1, col,m,n,grid,dp);
        int right = solve(row, col+1,m,n,grid,dp);

        return dp[row][col] = grid[row][col] + min(down,right);
    }

    int tabulation(int m,int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        dp[m-1][n-1]=grid[m-1][n-1];

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1){
                    dp[i][j]=grid[i][j];
                    continue;
                }

                int down=INT_MAX, right=INT_MAX;

                if(i<m-1){
                    down=dp[i+1][j];
                }

                if(j<n-1){
                    right=dp[i][j+1];
                }

                dp[i][j] = grid[i][j] + min(down,right);
            }
        }

        return dp[0][0];
    }

    int spaceOptimization(int m, int n, vector<vector<int>>& grid){
        vector<int> dp(n,0);

        for(int i=m-1;i>=0;i--){
            vector<int> temp(n);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1){
                    temp[j]=grid[i][j];
                    continue;
                }

                int down=INT_MAX, right=INT_MAX;

                if(i<m-1){
                    down=dp[j];
                }

                if(j<n-1){
                    right=temp[j+1];
                }

                temp[j] = grid[i][j] + min(down,right);
            }
            dp=temp;
        }

        return dp[0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(0,0,m,n,grid,dp);
        // return tabulation(m,n,grid,dp);
        return spaceOptimization(m,n,grid);
    }
};