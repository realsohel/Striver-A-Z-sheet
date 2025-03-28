#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// ======================================= OPTIMAL =======================================

    // Time Complexity: O(n^3 +log(n))
    // Space Complexity: O(1)

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(i!=0 and nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++){

                if(j!=i+1 and nums[j]==nums[j-1])
                continue;

                int k=j+1;
                int l=n-1;

                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];

                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l and nums[k]==nums[k-1])
                            k++;
                        while(k<l and nums[l]==nums[l+1])
                            l--;
                    }
                    else if(sum<target)
                        k++;
                    else
                        l--;
                    
                }
            }
        }
        return ans;
    }
    

// ======================================= BETTER =======================================

    // vector<vector<int>> fourSum(vector<int>& nums, int target) {

    //     int n = nums.size();
    //     set<vector<int>> st;

    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             set<long long> s;
                
    //             for(int k =j+1;k<n;k++){
    //                 long long l = nums[i]+nums[j];
    //                 l+=+nums[k];
    //                 long long sum = target - (l);
                    
    //                 if(s.find(sum)!=s.end()){
    //                     vector<int> v = {nums[i],nums[j],nums[k],(int)sum};
    //                     sort(v.begin(),v.end());
    //                     st.insert(v);
    //                 }else{
    //                     s.insert(nums[k]);
    //                 }
    //             }
    //         }
    //     }


    //     vector<vector<int>> ans(st.begin(),st.end());
    //     return ans;
    // }
};