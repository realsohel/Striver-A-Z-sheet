// Link: https://leetcode.com/problems/max-consecutive-ones-iii

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// OPTIMAL APPROACH
// T.C => O(N)
// S.C => O(1)
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int cnt=0;
        int maxi=0;

        while(j<n){
            if(nums[j]==0){
                cnt++;
            }

            if(cnt>k){
                if(nums[i]==0)
                    cnt--;
                i++;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi;

    }

// BETTER APPROACH
// T.C => O(2N)
// S.C => O(1)
    int longestOnes1(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int cnt=0;
        int maxi=0;

        while(j<n){
            if(nums[j]==0){
                cnt++;
            }
            while(cnt>k){
                if(nums[i]==0)
                    cnt--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi;

    }
};