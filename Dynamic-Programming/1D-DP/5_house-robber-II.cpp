#include <bits/stdc++.h> 
using namespace std;

// Everything is same as Maximum sum of non-adjacent elements problem, 
// just we have to take care of the first and last element as they are adjacent to each other.

class Solution { 

public:
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0)return nums[0];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int pick = nums[ind] + solve(ind-2, nums,dp);
        int notPick= 0 + solve(ind-1, nums,dp);

        return dp[ind]=max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int  n = nums.size();

        if(n==1) return nums[0];
        vector<int> temp1, temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp(n+1,-1);
        vector<int> dp1(n+1,-1);

        return max(solve(n-2, temp1,dp), solve(n-2, temp2,dp1));
    }
};