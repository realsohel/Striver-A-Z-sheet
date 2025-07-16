#include"bits/stdc++.h"
using namespace std;

class Solution {
public:

// Since each row and column is sorted, we can start from the top-right corner
// and move left or down based on the comparison with the target.
// Time Complexity: O(N+M)
// Space Complexity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m = matrix[0].size();

        int row=0,col=m-1;

        while(row<n and col>=0){

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                row++;
            }
            else
                col--;
        }

        return false;
    }
};