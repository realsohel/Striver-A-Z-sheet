#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Recursive
    int solve(vector<int> &nums,int low,int high,int target){
        int mid = (low+high)/2;

        if(low>high)
            return -1;
        
        if(nums[mid]==target)
            return mid;
        else if(target>nums[mid])
            return solve(nums,mid+1,high,target);
        else
            return solve(nums,low,mid-1,target);
        
        return -1;
    }

    int search(vector<int>& nums, int target) {

        return solve(nums,0,nums.size()-1,target);
    }

    // Iterative
    // int search(vector<int>& nums, int target) {
    //     int n = nums.size();

    //     int low=0,high=n-1;

    //     while(low<=high){
    //         int mid = (low+high)/2;

    //         if(nums[mid]==target)
    //             return mid;
    //         else if(nums[mid]<target){
    //             low=mid+1;
    //         }
    //         else
    //             high=mid-1;
    //     }

    //     return -1;

    // }
};

