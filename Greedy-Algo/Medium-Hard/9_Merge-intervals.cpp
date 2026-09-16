#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> vec;    
        vec.push_back(intervals[0]);

        for(int i=1; i<n;i++){
            if (intervals[i][0] <= vec.back()[1]) {
                vec.back()[1] = max(vec.back()[1], intervals[i][1]);
            } else {
                vec.push_back(intervals[i]);
            }
        }

        return vec;
    }
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> vec;

        int f=INT_MAX, s=INT_MIN;
        bool flg=0;
        for(int i=1; i<n;i++){
            if(intervals[i][0]<=intervals[i-1][1]){
                flg=true;
                f = min(f, min(intervals[i][0], intervals[i-1][0]));
                s = max(s, max(intervals[i][1], intervals[i-1][1]));
            }
            else{
                if(flg){
                    vec.push_back({f,s});
                }
                flg=false;
                vec.push_back(intervals[i]);

                f=INT_MAX; s=INT_MIN;
            }

        }

        if(f!=INT_MAX){
            vec.push_back({f,s});
        }

        return vec;
    }
};