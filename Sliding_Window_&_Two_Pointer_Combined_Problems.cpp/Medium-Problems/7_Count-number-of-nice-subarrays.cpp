// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>&nums,int k){
        if(k<0)
            return 0;
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        int cnt=0;

        while(i<n and j<n){
            if(nums[j]%2!=0)
                cnt++;
            
            if(cnt<=k){
                ans=ans+(j-i+1);
            }

            while(cnt>k){
                if(nums[i]%2!=0)
                    cnt--;
                i++;
                
                if(cnt<=k){
                    ans=ans+(j-i+1);
                }

            }
            j++;
        }

        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};