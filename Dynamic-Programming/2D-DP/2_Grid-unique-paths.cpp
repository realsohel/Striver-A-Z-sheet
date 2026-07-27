#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:

// Memoization - > Solved By Myself
    int solve(int row, int col,int m,int n, vector<vector<int>> &dp){
        if(row==m) return 0;
        if(col==n) return 0;

        if(row==m-1 and col==n-1) 
            return 1;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int right = solve(row,col+1,m,n,dp);
        int down = solve(row+1,col,m,n,dp);

        return dp[row][col]=(right+down);
    }

    
    int tabulation(int m,int n, vector<vector<int>> &dp){
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
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

    int spaceOptimization(int m,int n){
        vector<int> dp(n,1);

        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 and j==0) {
                    temp[0]=1;
                    continue;
                }
                int up=0, left=0;
                if(i>0)
                    up=dp[j];

                if(j>0)
                    left = temp[j-1];

                temp[j]=up+left;
            }

            dp=temp;
        }

        return dp[n-1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(0,0,m,n,dp);
        // return tabulation(m,n,dp);
        return spaceOptimization(m,n);
    }

    int uniquePaths1(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case
        dp[m - 1][n - 1] = 1;

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {

                if (row == m - 1 && col == n - 1)
                    continue;

                int right = (col + 1 < n) ? dp[row][col + 1] : 0;
                int down  = (row + 1 < m) ? dp[row + 1][col] : 0;

                dp[row][col] = right + down;
            }
        }

        return dp[0][0];
    }
};