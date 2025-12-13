// Link: https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// OPTIMAL APPROACH
// T.C => O(N)
// S.C => O(2)
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        int cnt=0;

        while(j<n and i<n){
            mp[nums[j]]++;

            if(mp.size()>2 and i<n){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            
            cnt=max(cnt,j-i+1);
            j++;
            
        }
        

        return cnt;
    }

// BETTER APPROACH
// T.C => O(2N)
// S.C => O(2)
    int totalFruit1(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        int cnt=0;

        while(j<n and i<n){
            mp[nums[j]]++;

            while(mp.size()>2 and i<n){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            
            cnt=max(cnt,j-i+1);
            j++;
            
        }
        

        return cnt;
    }
};