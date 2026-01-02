#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    struct compare{
        bool operator()(pair<int,int> a, pair<int,int> b) {
            return a.first > b.first;   
        }
    };
    
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        int n = arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;
        
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int cnt=0;
        int prev=-1;
        
        while(!pq.empty()){
            auto el = pq.top();
            int idx= el.second;
            
            if(prev!=el.first)
                cnt++;
                
            prev=el.first;
            arr[idx]=cnt;
            pq.pop();
        }
        
        return arr;
    }
};
