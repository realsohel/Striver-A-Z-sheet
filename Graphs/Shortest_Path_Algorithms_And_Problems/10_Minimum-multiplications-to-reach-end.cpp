#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1000 ;
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> dist(mod,INT_MAX);
        
        q.push({0,start});
        dist[start]=0;
        
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node==end)return steps;
            
            for(auto &x:arr){
                int num = (node*x)%mod;
                
                if(steps+1 <dist[num]){
                    dist[num]=steps+1;
                    
                    if(num==end)steps+1;
                    q.push({steps+1, num});
                }
                
            }
        }
        
        return -1;
    }
};