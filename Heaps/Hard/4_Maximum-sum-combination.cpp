#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        vector<int> ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        set<pair<int,int>> st;
        
        priority_queue<pair<int, pair<int,int>>>pq1;
        
        pq1.push({a.back()+b.back(), {n-1,n-1}}); 
        st.insert({n-1,n-1});
        
        while(k--){
            auto p = pq1.top();
            
            int sum = p.first;
            int i=p.second.first;
            int j=p.second.second;
            
            ans.push_back(sum);
            
            pq1.pop();
            
            if(st.find({i-1,j})==st.end()){
                pq1.push({a[i-1]+b[j], {i-1,j}});
                st.insert({i-1,j});
            }
            
            if(st.find({i,j-1})==st.end()){
                pq1.push({a[i]+b[j-1], {i,j-1}});
                st.insert({i,j-1});
            }
        }
        
        return ans;
        
    }
};