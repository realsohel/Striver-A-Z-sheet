// Link: https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>& nums, int goal) {
        if(goal<0)
            return 0;
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int cnt=0;

        while(j<n and i<n){
            sum+=nums[j];

            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            cnt = cnt+ (j-i+1);
            j++;
        }

        return cnt ;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums,goal-1);
    }
};