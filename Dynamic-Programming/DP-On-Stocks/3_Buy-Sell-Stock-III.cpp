#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int memo(int i, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int cnt){
        
        if(cnt==0)
            return 0;

        if(i==prices.size())
            return 0;
        
        if(dp[i][buy][cnt]!=-1){
            return dp[i][buy][cnt];
        }

        int prof=0;

        if(buy){
            prof = max( (-1)*prices[i] + memo(i+1,0,prices,dp,cnt) , 
                    0 + memo(i+1,1,prices,dp, cnt) );
        }
        else{
            prof = max( prices[i] + memo(i+1,1,prices,dp,cnt-1) , 
                    0 + memo(i+1,0,prices,dp,cnt) );
        }

        return dp[i][buy][cnt] = prof;
    }

    int tab(int n, vector<int>& prices){
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(2, vector<int>(3,0)));


        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=2;cnt++){
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

        return dp[0][1][2];
    }
    
    int space(int n, vector<int>& prices){
        vector<vector<int>> after(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=2;cnt++){
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

        return after[1][2];

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(2, vector<int>(3,-1)));

        int cnt=2;

        // return memo(0,1,prices,dp, cnt); 
        // return tab(n, prices); 
        return space(n, prices); 
    }
};