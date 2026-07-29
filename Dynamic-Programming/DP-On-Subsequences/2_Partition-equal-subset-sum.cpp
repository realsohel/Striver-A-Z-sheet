#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool solve(int idx, vector<int> &arr, int k, vector<vector<int>> &dp){
        if(k==0)
            return true;
        
        if(idx==0)
            return arr[idx]==k;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        bool notTake = solve(idx-1,arr,k,dp);
        bool take = false;
        
        if(k>=arr[idx]){
            take=solve(idx-1, arr, k-arr[idx], dp);
        }
        
        return dp[idx][k] = notTake || take;
    }
    bool tabulation(int n, vector<int> &arr, int k){
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
        
        return dp[n-1][k];
    }
    
    bool spaceOptimization(int n, vector<int>& arr, int k){
        vector<bool> prev(k+1, false) , curr(k+1,false);
        
        prev[0]=curr[0]=true;
        
        if (arr[0] <= k)
            prev[arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                
                bool notTake = prev[target];
                bool take=false;
                
                if(target>=arr[i]){
                    take=prev[target-arr[i]];
                }
                
                curr[target]= notTake | take;
            }
            prev=curr;
        }
        
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = accumulate(nums.begin(),nums.end(),0);
        
        if(target%2!=0) return false;
        target=target/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1, -1));

        // return solve(n-1, nums, maxi, dp);

        // return tabulation(n, nums,target);
        return spaceOptimization(n, nums,target);
    }
};