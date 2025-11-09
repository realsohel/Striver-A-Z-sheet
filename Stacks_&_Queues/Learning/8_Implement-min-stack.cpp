#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> stk;
    int minVal=0;
    MinStack() {    
        minVal=INT_MIN;
    }
    
    void push(int val) {
        if(stk.empty())
            minVal=val;
        
        minVal=min(minVal,val);
        stk.push({val,minVal});
    }
    
    void pop() {    
        if(stk.empty())
            return;
        stk.pop();
        
        if (!stk.empty())
            minVal = stk.top().second;
        else
            minVal = INT_MAX;
    }
    
    int top() {
        if(stk.empty())
            return -1;
        return stk.top().first;
    }
    
    int getMin() {
        if(stk.empty())
            return -1;
        return stk.top().second;
    }
};