#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Approach 2: A more cleaned version of Code.
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is even so its pair is mid + 1
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Unique element is after this pair
                low = mid + 2;
            } else {
                // Unique element is at mid or before
                high = mid;
            }
        }

        return nums[low];
    }

// Approach 1: 
// Time Complexity: O(log n)
// Space Complexity: O(1) 
    // int singleNonDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     int low = 0, high = n - 1;

    //     if (n == 1) 
    //         return nums[0];
    //     else if (nums[0] != nums[1]) 
    //         return nums[0];
    //     else if (nums[n - 1] != nums[n - 2]) 
    //         return nums[n - 1];

    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;

    //         // Unique element condition
    //         if ((mid == 0 || nums[mid] != nums[mid - 1]) && 
    //             (mid == n - 1 || nums[mid] != nums[mid + 1])) {
    //             return nums[mid];
    //         }

    //         // Determine where to go
    //         if (mid > 0 && nums[mid] == nums[mid - 1]) {
    //             int left_count = mid - low + 1;
    //             if (left_count % 2 == 0) {
    //                 low = mid + 1;
    //             } else {
    //                 high = mid - 2;
    //             }
    //         } else { // nums[mid] == nums[mid + 1]
    //             int right_count = high - mid + 1;
    //             if (right_count % 2 == 0) {
    //                 high = mid - 1;
    //             } else {
    //                 low = mid + 2;
    //             }
    //         }
    //     }

    //     return -1; // Shouldn't reach here if input is valid
    // }

};