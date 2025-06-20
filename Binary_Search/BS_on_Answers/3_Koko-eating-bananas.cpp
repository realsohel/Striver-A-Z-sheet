#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long func(vector<int>& piles, int h, int i){
        long long time = 0;

        for (int x = 0; x < piles.size(); x++) {
            time += (piles[x] + i - 1) / i;  
        }

        return time;
    }


// Optimal Approach - Binary Search
// Time Complexity: O(N * log(max(piles)))
// Space Complexity: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1;
        int high = *max_element(piles.begin(),piles.end()) ;  // O(N)

        while(low<=high){
            int mid = low + (high-low)/2;
            long long reqTime = func(piles,h,mid);
            
            if(reqTime<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }

        return low;
    }
    

// Brute Force Approach
// // Time Complexity: O(M * N)
// // Space Complexity: O(1)
    int minEatingSpeed1(vector<int>& piles, int h) {
        
        int maxi = *max_element(piles.begin(),piles.end());  // O(N)

        for(int i=1; i<=maxi;i++){ // // O(MAXI) => // O(M)
            int reqTime = func(piles,h,i);

            if(reqTime <= h)
                return i;
        }

        return -1;
    }
};