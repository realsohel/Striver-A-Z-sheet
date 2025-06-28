#include<bits/stdc++.h>
using namespace std;

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
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return ans;
    }

};