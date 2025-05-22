#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// Time Complexity: O(log n)
// Space Complexity: O(1)
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low=0, high=n-1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;

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
        
        return -1;
    }
};



int main(){

    return 0;
}