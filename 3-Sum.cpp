#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


// ======================================= OPTIMAL =======================================

    // Optimal Solution
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<nums.size();i++){
            if(i!=0 and nums[i]==nums[i-1])
                continue;

            int j=i+1, k=n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1])
                        j++;
                    while(j<k and nums[k]==nums[k+1])
                        k--;
                }
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }

        return ans;
    }


// ======================================= BETTER =======================================

    // // Better Approach
    // // Time Complexity: O(n^2)
    // // Space Complexity: O(n) + O(No. of unique triplets)*2
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> st;
    //     for(int i=0;i<nums.size();i++){
    //         set<int> s;
    //         for(int j=i+1;j<n;j++){
    //             int k = -(nums[i]+nums[j]);
    //             if(s.find(k)!=s.end()){
    //                 vector<int> v = {nums[i],nums[j],k};
    //                 sort(v.begin(),v.end());
    //                 st.insert(v);
    //             }
    //             else
    //                 s.insert(nums[j]);
    //         }
    //     }

    //     vector<vector<int>>ans(st.begin(),st.end());
    //     return ans;
    // }
    
// ======================================= BRUTE FORCE =======================================

    // // Brute Force Approach
    // // Time Complexity: O(n^3)
    // // Space Complexity: O(n)
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> st;

    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<n;j++){
    //             for(int k=j+1;k<n;k++){
    //                 if(nums[i]+nums[j]+nums[k]==0){
    //                     vector<int> v = {nums[i],nums[j],nums[k]};
    //                     sort(v.begin(),v.end());
    //                     st.insert(v);
    //                 }
    //             }
    //         }
    //     }

    //     vector<vector<int>>ans(st.begin(),st.end());
    //     return ans;
    // }

};

