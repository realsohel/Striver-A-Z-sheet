#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int sum2 = accumulate(nums.begin(), nums.end(), 0);

        

    }

// Approach 1: Using Hashing
// Time complexity: O(N)
// Space complexity: O(N)
    // vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    //     unordered_map<int,int> mp;

    //     for(int x:nums)
    //         mp[x]++;
        
    //     int first=0,second=0;
    //     for(int i=1;i<=nums.size();i++){
    //         if(mp[i]==0)
    //             second=i;
    //         else if(mp[i]==2)
    //             first=i;

    //         if(first!=0 and second!=0)
    //             break;
    //     }

    //     return {first,second};
    // }
};