#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char>stk;
        string ans="";

        for(int i=n-1;i>=0;i--){
            if(!stk.empty() and stk.top()=='*' and s[i]!='*'){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }

        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }

        return ans;
    }
};