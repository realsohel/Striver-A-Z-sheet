#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:

    int memo(int idx, int inches, vector<int> &price, vector<vector<int>> &dp){
        
        if(inches==0)
            return 0;
        
        if(idx==0){
            if(inches>0){
                return inches*price[0];
            }
            else return 0;
        }
        
        if(dp[idx][inches]!=-1){
            return dp[idx][inches];
        }
        
        
        int notTake = memo(idx-1, inches,price, dp);
        int take = 0;
        
        if(inches >= (idx+1)){
            take = price[idx] + memo(idx, inches-idx-1, price, dp);
        }
        
        return dp[idx][inches] = max(take,notTake);
    }
    
    int tabulation(int inches, vector<int> &price){
        
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(inches+1,0));
        
        for(int i=0;i<=inches;i++){
            dp[0][i] = i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=inches;j++){
                
                int notTake = dp[i-1][j];
                int take = 0;
                
                if(j >= (i+1)){
                    take = price[i] + dp[i][j-i-1];
                }
                
                dp[i][j] = max(take,notTake);
            }
        }
        
        return dp[n-1][inches];
        
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        
        // return memo(n-1, n, price, dp);
        return tabulation( n, price);
    }
};