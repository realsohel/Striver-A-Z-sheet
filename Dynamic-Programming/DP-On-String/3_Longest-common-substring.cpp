#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int maxi=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                    int prev = dp[i-1][j-1];
                    dp[i][j] = prev + 1;
                    
                    maxi = max(dp[i][j],maxi);
                }
                
            }
        }
        
        return maxi;
    }
};