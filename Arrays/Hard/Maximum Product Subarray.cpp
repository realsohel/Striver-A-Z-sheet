#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int maxi=INT_MIN;

        int pref=1,suff=1;

        for(int i=0;i<n;i++){
            if(pref==0){
                pref=1;
            }

            if(suff==0)
                suff=1;
            
            pref*=nums[i];
            suff*=nums[n-i-1];

            maxi=max(maxi, max(pref,suff));
        }
    
        return maxi;
    }


// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
    // int maxProduct(vector<int>& nums) {
    //     int maxProc=INT_MIN;
    //     int n = nums.size();
    //     int prod=0;
    //     for(int i=0;i<n;i++){
    //         prod =1;
    //         for(int j=i;j<n;j++){
    //             prod*=nums[j];
    //             maxProc = max(prod,maxProc);
    //         }
    //     } 
    //      maxProc = max(prod,maxProc);
    //     return maxProc;
    // }
};