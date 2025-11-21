#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!stk.empty() and stk.top()>=arr[i])
                stk.pop();
            
            if(stk.empty())
                ans[i]=-1;
            else
                ans[i]=stk.top();
            
            stk.push(arr[i]);
        }
        
        return ans;
    }
};