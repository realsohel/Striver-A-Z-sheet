#include<bits/stdc++.h>
using namespace std;

// Question: Find Minimum in Rotated Sorted Array
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Answer: This problem is a classic application of binary search on a rotated sorted array.
// The goal is to find the minimum element in a sorted and rotated array with unique elements.
//
// Key Observations:
// - The array was originally sorted in ascending order and then rotated.
// - The minimum element is the point of rotation (pivot).
//
// Approach:
// - Use binary search to efficiently locate the minimum element.
// - If the subarray nums[low] to nums[high] is already sorted (i.e., nums[low] <= nums[high]),
//   then nums[low] is the minimum in that range, and we can return it immediately.
//
// - If the left half [low...mid] is sorted (nums[low] <= nums[mid]),
//   then the minimum cannot be in this range except possibly at nums[low],
//   so we update mini and search in the right half (low = mid + 1).
//
// - Else, the right half [mid...high] must be sorted, and the pivot (minimum)
//   lies in the left half including mid, so we update mini and search left (high = mid - 1).
//
// Time Complexity: O(log n) – because we reduce the search space by half each time
// Space Complexity: O(1) – no extra space is used


class Solution {
public:

// Slightly More Optimized Approach
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0,high=n-1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[low] <= nums[high]){
                mini = min(mini , nums[low]);
                break;
            }

            if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }

        return mini;
    }

    
// Approach: Modified Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
    // int findMin(vector<int>& nums) {
    //     int n = nums.size();
    //     int low=0,high=n-1;
    //     int mini = INT_MAX;

    //     while(low<=high){
    //         int mid = low + (high-low)/2;

    //         if(nums[low]<=nums[mid]){
    //             mini=min(mini,nums[low]);
    //             low=mid+1;
    //         }
    //         else{
    //             mini=min(mini,nums[mid]);
    //             high=mid-1;
    //         }
            
    //     }

    //     return mini;
    // }
};