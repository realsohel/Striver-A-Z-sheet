#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string preToInfix(string s) {
        // Write your code here
        stack<string> stk;
        int n=s.size();
        
        for(int i=n;i>=0;i--){
            if(isalpha(s[i])){
                string temp(1, s[i]);
                stk.push(temp);
                continue;
            }    

            string t1 = stk.top();
            stk.pop();

            string t2 = stk.top();
            stk.pop();

            string ans = '(' + t1 + s[i] + t2 + ')';
            stk.push(ans);
        }
        
        return stk.top();
    }
};