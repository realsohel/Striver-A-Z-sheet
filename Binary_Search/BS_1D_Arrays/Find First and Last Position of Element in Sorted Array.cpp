#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Using Lower Bound and Upper Bound
    // Time Complexity: O(2*logN) ~~ O(logN)
    // Space Complexity: O(1)
    // Lower Bound: The first position where the element is greater than or equal to the target
    // Upper Bound: The first position where the element is greater than the target
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low=0,high =n-1;
        int ans=n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>=target){
                ans = mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        
        return ans;
    }


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

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        if(n==0)
            return {-1,-1};
        else if(n==1 ){
            if(nums[0]==target)
                return {0,0};
            else
                return {-1,-1};
        }

        int lb = lowerBound(nums,target);
        int ub = upperBound(nums,target);

        if(lb==n or nums[lb]!=target)
            return {-1,-1};
        
        return {lb,ub-1};
    }
};