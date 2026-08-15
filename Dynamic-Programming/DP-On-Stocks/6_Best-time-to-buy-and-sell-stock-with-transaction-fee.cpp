#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int i, int buy, vector<int>& prices,vector<vector<int>> &dp, int fee){

        if(i==prices.size())
            return 0;
        
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }

        int prof=0;

        if(buy){
            prof = max( (-1)*prices[i] + memo(i+1,0,prices,dp,fee) , 
                    0 + memo(i+1,1,prices,dp, fee) );
        }
        else{
            prof = max( prices[i] - fee + memo(i+1,1,prices,dp,fee) , 
                    0 + memo(i+1,0,prices,dp,fee) );
        }

        return dp[i][buy] = prof;
    }

    int tab(int n, int fee, vector<int>& prices){
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int prof=0;

                if(buy){
                    prof = max( (-1)*prices[i] + dp[i+1][0] , dp[i+1][1] );
                }
                else{
                    prof = max( prices[i] - fee + dp[i+1][1] , dp[i+1][0]);
                }

                dp[i][buy]=prof;
            }
        }

        return dp[0][1];
    }

    int space(int n, int fee, vector<int>& prices){
        vector<int> ahead(2,0), curr(2,0);

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int prof=0;

                if(buy){
                    prof = max( (-1)*prices[i] + ahead[0] , ahead[1] );
                }
                else{
                    prof = max( prices[i] - fee + ahead[1] , ahead[0]);
                }

                curr[buy]=prof;
            }
            ahead=curr;
        }

        return ahead[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        // return memo(0,1,prices,dp, fee); 
        // return tab(n, fee, prices);    
        return space(n,fee, prices);    
    }
};