#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int memo(int idx, int sum, int target, vector<int>& nums, vector<vector<int>> &dp){

        if(idx==0){
            int cnt=0;
            if(nums[0]+sum==target)
                cnt++;
            if(sum-nums[0]==target)
                cnt++;
            
            return cnt;
        }
        
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];

        int take=0;

        if(sum>=nums[idx]){
            int c1 = memo(idx-1,sum + nums[idx],target,nums, dp);
            int c2 = memo(idx-1,sum - nums[idx],target,nums, dp);
            take = c1+c2;
        }


        return dp[idx][sum]= take;
    }

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
    
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(),0);
        
        if (total < diff || (total - diff) % 2 != 0)
            return 0;
        
        int k = (total - diff)/2;
        
        vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        return solve(n-1, arr,k, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(nums,target);
    }   
};