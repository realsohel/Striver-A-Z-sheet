#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimized Approach
// Time Complexity: O(log n)
// Space Complexity: O(1)
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;
        int minVal = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If subarray is sorted
            if (arr[low] <= arr[high]) {
                if (arr[low] < minVal) {
                    minVal = arr[low];
                    ans = low;
                }
                break;
            }

            if (arr[low] <= arr[mid]) {
                // Left part is sorted
                if (arr[low] < minVal) {
                    minVal = arr[low];
                    ans = low;
                }
                low = mid + 1;
            } else {
                // Right part might contain min
                if (arr[mid] < minVal) {
                    minVal = arr[mid];
                    ans = mid;
                }
                high = mid - 1;
            }
        }

        return ans;
    }


// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
    // int findKRotation(vector<int> &arr) {
    //     int n=arr.size();
        
    //     for(int i=0;i<arr.size();i++){
    //         if((i<n-1) and (arr[i]>arr[i+1]))
    //             return i+1;
    //     }
        
    //     return 0;
    // }
};