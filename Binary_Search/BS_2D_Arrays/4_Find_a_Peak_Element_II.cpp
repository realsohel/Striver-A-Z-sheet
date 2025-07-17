#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimized Approach - Solved by me using Binary Search.
// Time Complexity: O(N*logM)
// Space Complexity: O(1)
// We will perform binary search on the columns of the matrix.
// We will find the maximum element in each column and then check if it is a peak element.
// A peak element is an element that is greater than or equal to its neighbors.
// We will return the first peak element we find.
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();

        int low=0,high=m-1;

        while(low<=high){
            int mid = low +(high-low)/2;

            int maxi = mat[0][mid], maxRow=0;

            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    maxRow=i;
                }
            }

            int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            }
            else if (leftVal > mat[maxRow][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1,-1};
    }
};