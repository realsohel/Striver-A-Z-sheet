#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int>ans;

        for(int &x:nums){
            mp[x]++;
        }
        
        for(auto it=mp.begin(); it!=mp.end(); it++){
            pq.push({it->second,it->first});
        }

        while(!pq.empty() and k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
        
    }
};