#include<bits/stdc++.h>
using namespace std;

// Answer: This problem is a classic application of binary search on the answer (search space).
// The goal is to place 'k' cows in 'n' stalls such that the minimum distance between any two cows is maximized.
//
// Key Observations:
// - The stalls are placed at different positions along a straight line.
// - To maximize the minimum distance between any two cows, we must try different distance values
//   and check if it's possible to place all cows with at least that distance between them.
//
// Approach:
// - First, sort the stall positions to make checking distances meaningful.
// - Use binary search on the distance between cows:
//     - The minimum possible distance (low) is 1.
//     - The maximum possible distance (high) is the difference between the farthest and nearest stalls.
//
// - For each mid distance:
//     - Use a helper function `canPlace()` to check if we can place 'k' cows such that
//       each cow is at least 'mid' distance apart from the previous one.
//     - If possible, it means we can try a larger distance (low = mid + 1) and update answer.
//     - Otherwise, we need to reduce the distance (high = mid - 1).
//
// Helper Function – canPlace():
// - Start by placing the first cow in the first stall.
// - Iterate through the sorted stalls and place the next cow only if the distance from
//   the last placed cow is >= mid.
// - If we can place at least 'k' cows, return true.
//
// Time Complexity: O(n * log(maxDist))
//   - n = number of stalls
//   - log(maxDist) = binary search on distance range [1, stalls[n-1] - stalls[0]]
//
// Space Complexity: O(1) – constant space used


class Solution {
public:

    bool canPlace(vector<int> &stalls, int k, int dist) {
        int cnt = 1; // First cow is always placed
        int last = stalls[0];
    
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - last >= dist) {
                cnt++;
                last = stalls[i];
            }
        }
    
        return cnt >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
    
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;
    
        while(low <= high) {
            int mid = low + (high - low) / 2;
    
            if(canPlace(stalls, k, mid)) {
                ans = mid;
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }
    
        return ans;
    }

};