#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimized Binary Search Approach -
// Time Complexity - O(log(min(m,n)))
// Space Complexity - O(1)
// where m and n are the sizes of the two arrays
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return kthElement(nums2, nums1,k);
        
            
        int low = max(0, k - n), high = min(k, m);
        
        while (low <= high) {
            int px = (low + high) / 2;     // Number of elements from nums1
            int py = k - px;               // Number of elements from nums2


            // Left half
            int x1 = px == 0 ? INT_MIN : nums1[px - 1];
            int x2 = py == 0 ? INT_MIN : nums2[py - 1];
            
            // Right half
            int x3 = px == m ? INT_MAX : nums1[px];
            int x4 = py == n ? INT_MAX : nums2[py];

            if (x1 <= x4 && x2 <= x3) {
                return max(x1, x2);
            }
            
            if (x1 > x4)
                high = px - 1;
            else
                low = px + 1;
        }
        
        return -1;
    
    }



// Brute Force Approach - 
// Time Complexity - O(m+n)
// Space Complexity - O(m+n)
// where m and n are the sizes of the two arrays
    int kthElement1(vector<int>& nums1, vector<int>& nums2, int k) {
        // code here
        vector<int> merged;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }
        
        while (i < nums1.size()) 
            merged.push_back(nums1[i++]);
        
        while (j < nums2.size()) 
            merged.push_back(nums2[j++]);
        return merged[k-1]; 
    }
};