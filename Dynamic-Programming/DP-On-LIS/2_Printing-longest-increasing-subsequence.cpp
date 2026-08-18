#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int lstIndx=0;
        
        for(int idx=0;idx<n;idx++){
            hash[idx]=idx;
            for(int prev=0;prev<idx; prev++){
                if(nums[prev]<nums[idx] and 1+ dp[prev] > dp[idx]){
                    
                    dp[idx] =  1+dp[prev];
                    hash[idx]=prev;
                    
                }
            }
            
            if(dp[idx]>maxi){
                maxi = dp[idx];
                lstIndx=idx;
            }
        }
        
        vector<int> lis(maxi);
        lis[0] = nums[lstIndx];
        int idx=1;
        
        while(hash[lstIndx]!=lstIndx){
            lstIndx=hash[lstIndx];
            lis[idx]=nums[lstIndx];
            idx++;
        }
        
        reverse(lis.begin(),lis.end());
        
        return lis;
        
    }
};