#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int i, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int k){
        
        if(k==0)
            return 0;

        if(i==prices.size())
            return 0;
        
        if(dp[i][buy][k]!=-1){
            return dp[i][buy][k];
        }

        int prof=0;

        if(buy){
            prof = max( (-1)*prices[i] + memo(i+1,0,prices,dp,k) , 
                    0 + memo(i+1,1,prices,dp, k) );
        }
        else{
            prof = max( prices[i] + memo(i+1,1,prices,dp,k-1) , 
                    0 + memo(i+1,0,prices,dp,k) );
        }

        return dp[i][buy][k] = prof;
    }

    int tab(int n, int k, vector<int>& prices){
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(2, vector<int>(k+1,0)));


        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=k;cnt++){
                    int prof=0;

                    if(buy){
                        prof = max( (-1)*prices[i] + dp[i+1][0][cnt] , 
                                0 + dp[i+1][1][cnt] );
                    }
                    else{
                        prof = max( prices[i] + dp[i+1][1][cnt-1] , 
                                0 + dp[i+1][0][cnt]);
                    }

                    dp[i][buy][cnt]=prof;
                }
            }
        }

        return dp[0][1][k];
    }
    
    int space(int n, int k, vector<int>& prices){
        vector<vector<int>> after(2, vector<int>(k+1,0));
        vector<vector<int>> curr(2, vector<int>(k+1,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=k;cnt++){
                    int prof=0;

                    if(buy){
                        prof = max( (-1)*prices[i] + after[0][cnt] , 
                                0 + after[1][cnt] );
                    }
                    else{
                        prof = max( prices[i] + after[1][cnt-1] , 
                                0 + after[0][cnt]);
                    }

                    curr[buy][cnt]=prof;
                }
            }
            after=curr;
        }

        return after[1][k];

    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(2, vector<int>(k+1,-1)));

        // return memo(0,1,prices,dp, k); 
        // return tab(n, k, prices); 
        return space(n, k, prices); 
    }
};