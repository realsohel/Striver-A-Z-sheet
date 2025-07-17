#include<bits/stdc++.h>
using namespace std;


// Answer: This problem is a classic application of binary search on a value range in a row-wise sorted 2D matrix.
// The goal is to find the median of the matrix without flattening or sorting the entire matrix.
//
// Key Observations:
// - Each row in the matrix is sorted in ascending order.
// - The total number of elements is (n * m), so the median is the element at position (n * m) / 2.
// - Instead of merging all rows into one array and sorting (which is costly), we can use binary search 
//   on the value range of the matrix to efficiently find the median.
//
// Approach:
// - First, determine the search range (low to high) by finding the minimum and maximum values in the matrix:
//     - Since rows are sorted, the minimum is among the first elements of each row,
//       and the maximum is among the last elements.
//
// - Use binary search on the value range [low, high] to find the median.
//   At each step:
//     - Choose mid = (low + high) / 2.
//     - Count how many elements in the matrix are less than or equal to mid using a helper function.
//         - For each row, use upper_bound to count how many values are ≤ mid.
//     - If the count is less than or equal to (n * m) / 2, search in the higher half (low = mid + 1).
//     - Else, search in the lower half (high = mid - 1).
//
// - When the loop ends, 'low' will be pointing to the smallest number for which the count of smaller
//   or equal elements is more than (n * m) / 2, which is the median.
//
// Time Complexity: O(log(max - min) * n * log m)
//   - log(max - min): Binary search over the value range.
//   - n * log m: For each mid value, we do upper_bound on each of n rows (which takes log m per row).
//
// Space Complexity: O(1) – no extra space is used except for variables.



class Solution {
public:

// Upper Bound
    int upperBound(vector<int>& arr, int target) {

        // code here
        int n = arr.size();
        int low=0,high =n-1;
        int ans=n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>target){
                ans = mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        
        return ans;
    }
    
    
    // How many numbers are smaller than equal to x
    int blackbox(vector<vector<int>> &mat, int x){
        int cnt=0;
        int n = mat.size();
        
        for(int i=0;i<n;i++){
            cnt+= upperBound(mat[i],x);
        }
            
        return cnt;
    }
    
    
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m = mat[0].size();
        int req = (n*m)/2;
        
        int low = INT_MAX, high = INT_MIN;
        for (const auto& row : mat) {
            auto row_minmax = minmax_element(row.begin(), row.end());
            low = min(low, *row_minmax.first);
            high = max(high, *row_minmax.second);
        }
        
        
        while(low<=high){
            int mid = low+(high-low)/2;
            
            int smalleq = blackbox(mat,mid);
            
            if(smalleq<=req)
                low=mid+1;
            else
                high=mid-1;
            
        }
        
        return low;

    }
};
