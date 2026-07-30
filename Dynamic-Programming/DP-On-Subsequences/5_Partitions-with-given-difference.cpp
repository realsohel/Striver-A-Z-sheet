#include <bits/stdc++.h> 
using namespace std;

class Solution {
    public:

    int solve(int idx, vector<int> &arr, int k, vector<vector<int>> &dp){

        if (idx == 0) {
            if (k == 0 && arr[0] == 0) return 2; 
            if (k == 0) return 1;
            if (arr[0] == k) return 1;
            
            return 0;
        }
        
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        int notTake = solve(idx-1,arr,k,dp);
        int take = 0;
        
        
        if(k>=arr[idx]){
            take=solve(idx-1, arr, k-arr[idx], dp);
        }
        
        return dp[idx][k] = notTake + take;
    }
    
    int tabulation(int n, vector<int> &arr, int k){
        vector<vector<int>> dp(n+1,vector<int>(k+1, 0));
        
        if (arr[0] == 0)
            dp[0][0] = 2;   
        else
            dp[0][0] = 1;    
        
        if (arr[0] != 0 && arr[0] <= k)
            dp[0][arr[0]] = 1;
        
        for(int i=1;i<n;i++){
            for(int target=0;target<=k;target++){
                int notTake = dp[i-1][target];
                int take = 0;
                
                if(target>=arr[i]){
                    take = dp[i-1][target-arr[i]];
                }
                
                dp[i][target] = notTake + take;
            }
        }
        return dp[n-1][k];
        
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(),0);
        
        if (total < diff || (total - diff) % 2 != 0)
            return 0;
        
        int k = (total - diff)/2;
        
        vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        // return solve(n-1, arr,k, dp);
        
        return tabulation(n, arr,k);
    }
};