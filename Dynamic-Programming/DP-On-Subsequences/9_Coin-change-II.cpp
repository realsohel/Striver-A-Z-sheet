#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
    
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return 1;

            return 0;
        }

        if(dp[idx][amount]!=-1)
            return dp[idx][amount];

        int notTake = memo(idx-1,amount, coins, dp);
        int take =0;

        if(amount>=coins[idx]){
            take = memo(idx,amount - coins[idx], coins, dp);
        }

        return dp[idx][amount] = (notTake+take);
    }

    int tabulation(int n, int amount, vector<int>& coins){
        vector<vector<long long>> dp(n, vector<long long>(amount+1,0));

        int g = coins[0];
        for (int coin : coins)
            g = __gcd(g, coin);

        if (amount % g != 0)
            return 0;

        for(int i=0;i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i]=1;
            }
        }

        for(long long i=1;i<n;i++){
            for(long long j=0; j<=amount; j++){

                long long notTake = dp[i-1][j];
                long long take = 0;

                if(j>=coins[i]){
                    take = dp[i][j-coins[i]];
                }

                dp[i][j] = notTake + take;
            }
        }

        return (int)dp[n-1][amount];
    }

    int space(int n, int amount, vector<int>& coins){
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        
        // int ans =  memo(n-1, amount,coins, dp);
        // return ans;
        
        // return tabulation(n, amount,coins);
        return space(n, amount,coins);
    }
};