// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>& nums, int k){
        if(k<0)
            return 0;
        
        int n = nums.size();
        int i=0,j=0;
        int cnt=0;
        unordered_map<int,int> mp;

        while(j<n and i<n){
            mp[nums[j]]++;

            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                
                i++;
            }

            cnt+= (j-i+1);
            j++;
        } 
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};