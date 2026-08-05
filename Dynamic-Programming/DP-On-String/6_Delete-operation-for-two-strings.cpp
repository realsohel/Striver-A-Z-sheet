#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp){
        if(idx1<0 || idx2<0)
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];

        if(text1[idx1]==text2[idx2])
            return dp[idx1][idx2] = 1 + memo(idx1-1, idx2-1 , text1, text2, dp);
        
        return dp[idx1][idx2] = max( memo(idx1-1,idx2,text1, text2, dp), memo(idx1,idx2-1,text1, text2, dp) );
    }

    int tabulation(int n, int m, string &text1, string &text2){
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n; i++){
            for(int j=1;j<=m;j++){
                
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }



    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));

        // int lcs = memo(n-1,m-1,word1, word2, dp);

        int lcs = tabulation(n,m, word1, word2);

        return (n-lcs) + (m-lcs);
    }
};