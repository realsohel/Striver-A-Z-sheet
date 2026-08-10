#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){

        if(i < 0)
            return j + 1;

        if(j < 0)
            return i + 1;   

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ins = 0 ,rep=0, del=0;

        if(s[i]==t[j]){
            return dp[i][j] = memo(i-1,j-1,s,t,dp);
        } 
        else {
            rep = 1 + memo(i-1,j-1,s,t, dp);
            del = 1+ memo(i-1,j,s,t,dp);
            ins = 1+ memo(i,j-1,s,t,dp);

            return dp[i][j] = min({rep,del,ins});
        }
        
    }

    int tabulation(int n, int m, string &s, string &t){
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }

        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }

        for(int i=1;i<=n ;i++){
            for(int j=1;j<=m;j++){
                
                int ins = 0 ,rep=0, del=0;

                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } 
                else {
                    rep = 1 + dp[i-1][j-1];
                    del = 1+ dp[i-1][j];
                    ins = 1+ dp[i][j-1];

                    dp[i][j] = min({rep,del,ins});
                }

            }
        }

        return dp[n][m];
    }

    int spaceOptimization(int n, int m, string &s, string &t){
        vector<int> prev(m+1,0) , curr(m+1,0);

        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for(int i=1;i<=n ;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                
                int ins = 0 ,rep=0, del=0;

                if(s[i-1]==t[j-1]){
                    curr[j] = prev[j-1];
                } 
                else {
                    rep = 1 + prev[j-1];
                    del = 1+ prev[j];
                    ins = 1+ curr[j-1];

                    curr[j] = min({rep,del,ins});
                }

            }

            prev=curr;
        }

        return prev[m];
    }



    int minDistance(string word1, string word2) {
        int n = word1.size();    
        int m = word2.size();    

        vector<vector<int>> dp(n, vector<int>(m,-1));

        // return memo(n-1,m-1, word1, word2, dp);
        // return tabulation(n,m, word1, word2);
        return spaceOptimization(n,m, word1, word2);

    }
};