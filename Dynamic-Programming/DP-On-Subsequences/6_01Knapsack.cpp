#include <bits/stdc++.h> 
using namespace std;

int memo(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
    
    if(idx==0){
        if(W>=wt[0])
            return val[0];
        return 0;
    }
    
    if(dp[idx][W]!=-1)
        return dp[idx][W];
    
    int notTake = 0 + memo(idx-1, W, val, wt, dp);
    int take= INT_MIN;
    
    if(W>=wt[idx]){
        take = val[idx] + memo(idx-1, W-wt[idx], val, wt, dp);
    }
    
    return dp[idx][W] = max(notTake, take);
}

int tabulation(int n, int W, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    for(int i=wt[0]; i<=W;i++){
        dp[0][i]=val[0];
    }

    for(int i=1; i<n;i++){
        for(int j=0;j<=W;j++){
            int notTake = dp[i-1][j];

            int take= INT_MIN;

            if(j>=wt[i]){
                take = val[i] + dp[i-1][j-wt[i]];
            }

            dp[i][j] = max(notTake,take);
        }

    }
    return dp[n-1][W];
    
}
int spaceOptimization(int n, int W, vector<int> &val, vector<int> &wt){
    vector<int> prev(W+1,0) , curr(W+1,0);
    
    for(int i=wt[0]; i<=W;i++){
        prev[i]=val[0];
    }

    for(int i=1; i<n;i++){
        for(int j=0;j<=W;j++){
            int notTake = prev[j];

            int take= INT_MIN;

            if(j>=wt[i]){
                take = val[i] + prev[j-wt[i]];
            }

            curr[j] = max(notTake,take);
        }

        prev=curr;

    }
    return prev[W];
    
}

int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
            
    // return memo(n-1, W, val,wt,dp);
    // return tabulation(n, W, val,wt);
    return spaceOptimization(n, W, val,wt);
}