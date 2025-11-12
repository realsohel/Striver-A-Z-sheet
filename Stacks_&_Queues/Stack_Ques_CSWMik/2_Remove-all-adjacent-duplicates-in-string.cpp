#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        stk.push(s[0]);

        for(int i=1;i<s.size();i++){
            if(!stk.empty() and s[i]==stk.top()){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        
        string ans= "";

        while(!stk.empty()){
            ans=stk.top() + ans;
            stk.pop();
        }

        return ans;
    } 
};