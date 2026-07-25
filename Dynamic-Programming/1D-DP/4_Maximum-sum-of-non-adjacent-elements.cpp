#include <bits/stdc++.h> 
using namespace std;


// 1. Memoization
int solve(int ind, vector<int> &nums, vector<int> &dp){
    if(ind==0)return nums[0];
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick = nums[ind] + solve(ind-2, nums,dp);
    int notPick= 0 + solve(ind-1, nums,dp);

    return dp[ind]=max(pick,notPick);
}

// 2. Tabulation 
int solve1(int n, vector<int> &nums, vector<int> &dp){
    dp[0]=nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        int pick=0, notPick=0;
        
        pick = nums[i] + dp[i-2];
        notPick = 0 + dp[i-1];

        dp[i] = max(pick,notPick);
    }

    return dp[n-1];
}

// 3. Space Optimization 
int solve2(int n, vector<int> &nums){
    if(n==1) return nums[0];

    int prev2=nums[0], prev=max(nums[0], nums[1]); ;

    for(int i=2;i<n;i++){
        int pick = nums[i] + prev2; 
        int notPick = 0 + prev;

        prev2 = prev;
        prev=max(pick,notPick);
    }

    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int  n = nums.size();
    vector<int> dp(n+1,-1);

    return solve(n, nums,dp);
}


