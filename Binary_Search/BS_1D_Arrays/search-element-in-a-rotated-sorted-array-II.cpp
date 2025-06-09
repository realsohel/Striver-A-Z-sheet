// Answer: Yes, this problem is an extension of the standard "Search in Rotated Sorted Array".
// The only difference is that the array can now contain duplicate elements.

// When duplicates are present, we cannot always determine which side (left or right) is sorted,
// especially if nums[low] == nums[mid] == nums[high].
// In such cases, we cautiously shrink the search window by doing low++ and high-- to skip the duplicates.

// The overall approach is still a modified binary search:
// - If we can determine the sorted half, we check if the target lies within it.
// - If not, we move to the other half.
// - We continue this until we either find the target or exhaust the search space.

// Time Complexity:
// - Average case: O(log n)
// - Worst case (when many duplicates are present): O(n)
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Time Complexity: O(log n)
// Space Complexity: O(1)
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low=0, high=n-1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;

            // Handle duplicates 
            if((nums[low]==nums[mid]) and (nums[mid]==nums[high])){
                low++;
                high--;
                continue;
            }

            // left Sorted ? 
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target and nums[mid]>=target)
                    high = mid-1; // search in left
                else
                    low = mid+1; // search in right
            }
            else{ // Right Sorted ?
                if(nums[mid]<=target and nums[high]>=target)
                    low = mid+1; // search in right
                else
                    high = mid-1; // search in left
            }
        }
        
        return false;
    }
};



