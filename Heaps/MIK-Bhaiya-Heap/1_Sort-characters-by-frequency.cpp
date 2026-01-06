#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans;

        for(char &x:s){
            mp[x]++;
        }
        
        for(auto it=mp.begin(); it!=mp.end(); it++){
            pq.push({it->second,it->first});
        }

        while(!pq.empty()){
            int cnt=pq.top().first;
            while(cnt>0){
                ans.push_back(pq.top().second);
                cnt--;
            }
            pq.pop();
        }

        return ans;
        
    }
};