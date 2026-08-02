#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
    
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if(dp[idx][amount]!=-1)
            return dp[idx][amount];

        int notTake = memo(idx-1,amount, coins, dp);
        int take =1e9;

        if(amount>=coins[idx]){
            take = 1+ memo(idx,amount - coins[idx], coins, dp);
        }

        return dp[idx][amount] = min(notTake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        
        int ans =  memo(n-1, amount,coins, dp);

        if(ans>=1e9)
            return -1;
        return ans;
    }
};