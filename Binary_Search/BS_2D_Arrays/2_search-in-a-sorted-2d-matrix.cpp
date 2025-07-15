#include"bits/stdc++.h"
using namespace std;

class Solution {
public:

// Since each row is sorted, we can apply Binary Search on each row to find the target.
// Time Complexity: O(N*logM)
// Space Complexity: O(1)
    bool isPresent(vector<int>a,int target){
        int low=0,high=a.size()-1;

        while(low<=high){
            int mid =low+(high-low)/2;

            if(a[mid]==target)
                return true;
            else if(a[mid]<target){
                low=mid+1;
            }
            else
                high=mid-1;
        }

        return false;

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++){
            if(isPresent(matrix[i],target))
                return true;
        }

        return false;
    }
};