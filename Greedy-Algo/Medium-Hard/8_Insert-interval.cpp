#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> vec;
        int i=0;

        while(i<n and intervals[i][1] < newInterval[0]){
            vec.push_back(intervals[i]);
            i++;
        }

        while(i<n and intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            i++;
        }

        vec.push_back(newInterval);

        while(i<n){
            vec.push_back(intervals[i]);
            i++;
        }

        return vec;
    }

    //  TRIED But Failed
    vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> vec;
        int f = -1, s = -1, idx = -1;

        for (int i = 0; i < n; i++) {
            if (intervals[i][1] >= newInterval[0]) {
                f = min(intervals[i][0], newInterval[0]);
                idx = i;
                break;
            }
            else {
                vec.push_back(intervals[i]);
            }
        }

        if (idx == -1) {
            vec.push_back(newInterval);
            return vec;
        }

        s = newInterval[1];

        for (int i = idx; i < n; i++) {
            if (intervals[i][0] <= newInterval[1]) {
                s = max(s, intervals[i][1]);
                idx = i;
            }
            else {
                break;
            }
        }

        vec.push_back({f, s});

        for (int i = idx + 1; i < n; i++) {
            vec.push_back(intervals[i]);
        }

        return vec;
    }
};