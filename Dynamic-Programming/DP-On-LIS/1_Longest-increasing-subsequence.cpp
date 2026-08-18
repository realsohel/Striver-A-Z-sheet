#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int idx,int prev, int n, vector<int>& nums, vector<vector<int>> &dp){
        if(idx==n){
            return 0;
        }

        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1]; 
        }

        int notTake = 0 + memo(idx+1, prev, n, nums, dp);
        int take=0;
        
        if(prev ==-1 || nums[idx]>nums[prev]){
            take = 1 + memo(idx+1, idx,n, nums, dp);
        }

        return dp[idx][prev+1] = max(notTake, take);
    }

    int tab(int n, vector<int>& nums){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int idx=n-1; idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){

                int notTake = 0 + dp[idx+1][prev+1];
                int take=0;
                
                if(prev ==-1 || nums[idx]>nums[prev]){
                    take = 1 + dp[idx+1][idx+1];
                }

                dp[idx][prev+1] = max(notTake, take);
            }
        }
        return dp[0][0];
    }

    int space(int n, vector<int>& nums){
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for(int idx=n-1; idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){

                int notTake = 0 + next[prev+1];
                int take=0;
                
                if(prev ==-1 || nums[idx]>nums[prev]){
                    take = 1 + next[idx+1];
                }

                curr[prev+1] = max(notTake, take);
            }

            next=curr;
        }
        return next[0];

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        // return memo(0,-1,n, nums, dp);
        // return tab(n, nums);
        return space(n, nums);
    }
};