#include<bits/stdc++.h>
using namespace std;

// This and Painter's partition problem are very similar problems. Same Code
// 1. Book Allocation Problem
// 2. Painter's Partition Problem
// 3. Split Array Largest Sum

// All three problems can be solved using the same code with minor changes.

class Solution {
public:

    int helper(vector<int>& nums, int sum){
        int arrsum = 0;
        int cnt = 1;

        for(int i = 0; i < nums.size(); i++){
            if(arrsum + nums[i] <= sum){
                arrsum += nums[i];
            }
            else{
                cnt++;
                arrsum = nums[i];
            }
        } 
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(low<= high){

            int mid = low + (high-low)/2;

            int chk = helper(nums, mid);

            if(chk <= k){
                high=mid-1;
            }
            else
                low=mid+1;
        }

        return low;
    }

    int splitArray1(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        for(int i = low; i <= high; i++){
            int chk = helper(nums, i);

            if(chk <= k){
                ans = i;
                break;
            }
        }

        return ans;
    }
};
