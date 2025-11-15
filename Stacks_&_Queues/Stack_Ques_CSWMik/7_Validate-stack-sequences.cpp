#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();

        stack<int> stk;
        int i=0,j=0;
        while(i<n and j<n){
            stk.push(pushed[i]);

            while(!stk.empty() and popped[j]==stk.top()){
                stk.pop();
                j++;
            }
            i++;
        }

        return stk.empty();
    } 
};