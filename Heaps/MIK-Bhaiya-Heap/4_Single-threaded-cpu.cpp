#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> ans;

        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(),tasks.end());

        long long curr_time=0;
        int idx=0;

        while(idx<n or !pq.empty()){
            
            if(pq.empty() and curr_time<tasks[idx][0]){
                curr_time=tasks[idx][0];
            }

            while(idx<n and tasks[idx][0] <=curr_time){
                pq.push({tasks[idx][1],tasks[idx][2]}); // proceesing time, index.
                idx++;
            }

            auto task = pq.top();
            pq.pop();

            curr_time+=task.first;
            ans.push_back(task.second);
        }

        return ans;
    }
};