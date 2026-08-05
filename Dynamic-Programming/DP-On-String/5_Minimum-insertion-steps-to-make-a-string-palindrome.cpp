#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int tabulationInt(int n, int m, string &text1, string &text2, vector<vector<int>> &dp){
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));

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

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        int len = tabulationInt(n,n, s, s1,dp);

        string ans = "";

        for(int i=0;i<len;i++){
            ans+="@";
        }

        int i=n, j=n;
        int idx=len-1;

        while(i>0 and j>0){

            if(s[i-1]==s1[j-1]){
                ans[idx] = s1[i-1];
                idx--;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        return ans.size();
    }

    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    }
};