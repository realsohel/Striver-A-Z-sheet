#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int i, int buy, vector<int>& prices,vector<vector<int>> &dp){

        if(i>=prices.size())
            return 0;
        
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }

        int prof=0;

        if(buy){
            prof = max( (-1)*prices[i] + memo(i+1,0,prices,dp) , 
                    0 + memo(i+1,1,prices,dp) );
        }
        else{
            prof = max( prices[i] + memo(i+2,1,prices,dp) , 
                    0 + memo(i+1,0,prices,dp) );
        }

        return dp[i][buy] = prof;
    }

    int tab(int n, vector<int>& prices){
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int prof=0;

                if(buy){
                    prof = max( (-1)*prices[i] + dp[i+1][0] , dp[i+1][1] );
                }
                else{
                    prof = max( prices[i] + dp[i+2][1] , dp[i+1][0]);
                }

                dp[i][buy]=prof;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        // return memo(0,1,prices,dp); 
        return tab(n,prices);    
    }
};