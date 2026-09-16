#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int n, int idx, vector<int> &dp){
        if(idx>=n-1)
            return 0;
        
        int mini=1e9;

        if(dp[idx]!=-1)
            return dp[idx];

        for(int i=1; i<=nums[idx];i++){

            int nxt = i+idx;

            if(nxt<n){
                int jumps = solve(nums,n, i+idx, dp);

                mini = min(mini, 1+jumps);
            }

        }

        return dp[idx] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        return solve(nums, n, 0, dp);    
    }
};