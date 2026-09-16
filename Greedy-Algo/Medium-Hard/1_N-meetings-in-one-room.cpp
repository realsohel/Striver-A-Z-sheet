#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n = start.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<n;i++){
            vec.push_back({start[i], end[i]});
        }

        sort(vec.begin(), vec.end(), [](auto a, auto b) {
            return a.second < b.second; 
        });

        int cnt=1;
        int prev=vec[0].second;

        for(int i=0;i<n;i++){
            if(vec[i].first > prev){
                prev = vec[i].second;
                cnt++;
            }
        }

        return cnt;
    }
};