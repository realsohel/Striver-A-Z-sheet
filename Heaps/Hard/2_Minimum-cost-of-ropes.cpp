#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& arr) {
        // code here
        
        if(arr.size()==1) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int &x:arr)
            pq.push(x);
        
        int sum=0;
        
        while(!pq.empty()){
            int first  = pq.top();
            int second=0;
            pq.pop();
            
            if(!pq.empty()){
                second=pq.top();
                pq.pop();
            }
            
            sum+= first+second;
            
            if(!pq.empty())
                pq.push(first+second);
        }
        
        return sum;
    }
};