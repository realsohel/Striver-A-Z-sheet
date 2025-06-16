#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// More Cleaner version of the Optimized Approach
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int findPeakElement3(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        else if(n==2)
            return nums[0]>nums[1] ? 0 : 1;

        int low = 0, high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid + 1]) {
                // We are in the decreasing part of the array
                high = mid;
            } else {
                // We are in the increasing part of the array
                low = mid + 1;
            }
        }
        return low; // or high, both will be the same
    }


// Optimized Approach - Solved by me using Binary Search.
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int findPeakElement2(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        else if(n==2)
            return nums[0]>nums[1] ? 0 : 1;

        if(nums[0]>nums[1])
            return 0;
        else if(nums[n-1] > nums[n-2])
            return n-1;

        int low = 0, high = n - 1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if((mid > 0 and nums[mid]>nums[mid-1]) and (mid<n-1 and nums[mid] > nums[mid+1]))
                return mid;

            if(mid > 0 and nums[mid] < nums[mid-1]) 
                high=mid-1;
            else
                low=mid+1;
        }

        
        return 0;
    
    }


// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        else if(n==2)
            return nums[0]>nums[1] ? 0 : 1;
        
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1])
                return i;
        }

        if(nums[n-1] > nums[n-2])
            return n-1;

        return 0;
    }
};
