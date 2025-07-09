#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// Optimal Approach
// Time Complexity: O(log(min(m, n)))
// Space Complexity: O(1)
// This approach uses binary search to find the median in logarithmic time.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = m;

        while (low <= high) {
            int px = low + (high - low) / 2;
            int py = (m + n + 1) / 2 - px;

            // Left half
            int x1 = px == 0 ? INT_MIN : nums1[px - 1];
            int x2 = py == 0 ? INT_MIN : nums2[py - 1];
            
            // Right half
            int x3 = px == m ? INT_MAX : nums1[px];
            int x4 = py == n ? INT_MAX : nums2[py];

            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) % 2 == 0) {  // Fixed condition
                    double ans = max(x1, x2) + min(x3, x4);
                    return ans / 2.0;
                }
                else
                    return max(x1, x2);
            }
            
            if (x1 > x4)
                high = px - 1;
            else
                low = px + 1;
        }
        
        return -1;
    }


// Better Approach
// Time Complexity: O(m+n)
// Space Complexity: O(1)
// This approach uses two pointers to find the median without merging the arrays.
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int size = n+m;
        int cnt = 0;
        int i = 0, j = 0;

        int ind1 = (size - 1) / 2;
        int ind2 = size / 2;

        int el1=-1,el2=-1;

        while (i <n  && j < m) {
            if (nums1[i] < nums2[j]){
                if(cnt==ind1)
                    el1= nums1[i];
                if(cnt==ind2)
                    el2= nums1[i];
                i++;
                cnt++;
            }
            else{
                if(cnt==ind1)
                    el1= nums2[j];
                if(cnt==ind2)
                    el2= nums2[j];
                j++;
                cnt++;
            }
            
        }
        
        while (i < n) {
            if(cnt==ind1)
                el1= nums1[i];
            if(cnt==ind2)
                el2= nums1[i];
            i++;
            cnt++;
        }
        
        while (j < m) {
            if(cnt==ind1)
                el1= nums2[j];
            if(cnt==ind2)
                el2= nums2[j];
            j++;
            cnt++;
        }

        if(size%2==1)
            return el2;
        
        return (double)(el1+el2)/2.0;
    }


// Brute Force Approach
// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
// This approach merges the two sorted arrays and then finds the median.
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
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

        int n = merged.size();
        if (n % 2 == 0) {
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        } else {
            return merged[n/2];
        }
    }

};