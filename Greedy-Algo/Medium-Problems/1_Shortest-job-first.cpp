// Link - https://www.geeksforgeeks.org/problems/shortest-job-first/1
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
// OPTIMAL 
// TIME => O(NLOGN)
// SPACE=> O(1)
    long long solve(vector<int>& bt) {
        // code here
        int n =bt.size();
        
        sort(bt.begin(),bt.end());
        
        int tim=0, wait=0;
        
        for(int i=0;i<n;i++){
            wait+=tim;
            tim+=bt[i];
        }
        
        return wait/n;
    }
};