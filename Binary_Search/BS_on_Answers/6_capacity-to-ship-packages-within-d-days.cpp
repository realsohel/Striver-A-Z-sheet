#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& weights, int days, int cap) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > cap) {
                days--;
                sum = 0;
            }

            sum += weights[i];
        }
        return days > 0;
    }

// Optimal Approach - Binary Search
// Time Complexity: O(n * log(sum(weights)))
// Space Complexity: O(1)

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<=high){

            int mid = low + (high-low)/2;

            if(helper(weights,days,mid)) {
                high=mid-1;
            }  
            else
                low=mid+1;
                
        }

        return low;
    }


    // Brute Force Approach
    // Time Complexity: O(n * sum(weights))
    // Space Complexity: O(1)
    int shipWithinDays1(vector<int>& weights, int days) {

        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);

        for(int i=start;i<=end;i++){
            if(helper(weights,days,i))   
                return i;
        }

        return -1;
    }
};