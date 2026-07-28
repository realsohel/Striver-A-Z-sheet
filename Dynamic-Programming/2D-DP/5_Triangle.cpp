#include <bits/stdc++.h> 
using namespace std;

// IN THIS QUESTOIN EVERYTHING IS SOLVED BY MYSELF
class Solution {
public:
    int solve(int i, int j, int n, const vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i >= n or j>=n) 
            return 0;
        
        if (i == n - 1)
            return triangle[i][j];
        
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        
        int left = solve(i + 1, j, n, triangle, dp);
        int right = solve(i + 1, j + 1, n, triangle, dp);

        dp[i][j] = triangle[i][j] + min(left, right);

        return dp[i][j];
    }

    int tabulation(int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){

        for(int i=n-1;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0; j--){
                if(i==n-1){
                    dp[i][j] = triangle[i][j];
                    continue;
                }

                int left=INT_MAX, right=INT_MAX;

                left = dp[i+1][j];

                if(j<n-1){
                    right = dp[i+1][j+1];
                }

                dp[i][j] = triangle[i][j] + min(left,right);
            }
        }

        return dp[0][0];
    }
    int spaceOptimization(int n, vector<vector<int>>& triangle){
        vector<int> dp(n,INT_MAX);

        for(int i=n-1;i>=0;i--){
            vector<int> temp(n);

            for(int j=triangle[i].size()-1;j>=0; j--){
                if(i==n-1){
                    temp[j] = triangle[i][j];
                    continue;
                }

                int left=INT_MAX, right=INT_MAX;

                left = dp[j];

                if(j<n-1){
                    right = dp[j+1];
                }

                temp[j] = triangle[i][j] + min(left,right);
            }
            dp = temp;
        }

        return dp[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // return solve(0, 0, n, triangle, dp);
        // return tabulation(n, triangle, dp);
        return spaceOptimization(n, triangle);
    }
};