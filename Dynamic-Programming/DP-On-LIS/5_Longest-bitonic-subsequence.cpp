#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        
        // Forward Inc
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx; prev++){
                if(nums[prev]<nums[idx])
                    dp1[idx] = max(dp1[idx], 1+dp1[prev]);
            }
        }
        
        // Backward Inc
        
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=n-1;prev>idx; prev--){
                if(nums[prev]<nums[idx])
                    dp2[idx] = max(dp2[idx], 1+dp2[prev]);
            }
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++){
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        
        return maxi;
    }
};
