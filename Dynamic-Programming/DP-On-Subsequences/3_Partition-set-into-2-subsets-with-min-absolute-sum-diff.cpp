#include <bits/stdc++.h> 
using namespace std;


class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
        int k = accumulate(arr.begin(),arr.end(),0);
        
        int n=arr.size();
        
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if (arr[0] <= k)
            dp[0][arr[0]] = true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTake = dp[i-1][target];
                bool take=false;
                
                if(target>=arr[i]){
                    take=dp[i-1][target-arr[i]];
                }
                
                dp[i][target]= notTake | take;
            }
        }
        
        
        // Real question
        int mini = INT_MAX;
        for(int s1=0;s1<=k/2;s1++){
            
            if(dp[n-1][s1]==true){
                mini = min(mini, (k-s1) - s1);
            }
        }
        
        return mini;
    }
};
