#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> stk;

        for(int i=0;i<n;i++){
            if(stk.empty()){
                stk.push(ast[i]);
                continue;
            }

            bool destroyed = false;

            while(!stk.empty() and stk.top()>0 and ast[i]<0){
                if(stk.top()>abs(ast[i])){
                    destroyed = false;
                    break;
                }
                else if(stk.top()<abs(ast[i])){
                    stk.pop();
                }
                else{
                    stk.pop();
                    destroyed=true;
                    break;
                }
            }
            
            if (!destroyed) {
                if (stk.empty() || stk.top() < 0 || ast[i] > 0)
                    stk.push(ast[i]);
            }
        }

        vector<int> ans(stk.size(),0);
        int idx = stk.size()-1;

        while(!stk.empty()){
            ans[idx] = stk.top();
            stk.pop();
            idx--; 
        }

        return ans;
    }
};