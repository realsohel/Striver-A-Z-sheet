#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Optimal 
// T.C => O(N + N) ~O(2N)
// S.C => O(N)
    int kthSmallest(vector<int> &nums, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),nums.end());
        
        while(!pq.empty() and k>1){
            pq.pop();
            k--;
        }

        return pq.top();
    }
};