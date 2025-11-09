#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToPre(string s) {
        // Write your code here
        stack<string> stk;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                string temp(1, s[i]);
                stk.push(temp);
                continue;
            }    
            
            string t1 = stk.top();
            stk.pop();
            string t2 = stk.top();
            stk.pop();
            
            string ans = s[i] + t2 +  t1 ;
            stk.push(ans);
        }
        
        return stk.top();
    }

    string preToPost(string s) {
        // Write your code here
        stack<string> stk;
        int n=s.size();
        
        for(int i=n-1;i>=0;i--){
            if(isalpha(s[i])){
                string temp(1, s[i]);
                stk.push(temp);
                continue;
            }    
            
            string t1 = stk.top();
            stk.pop();
            string t2 = stk.top();
            stk.pop();
            
            string ans = t1+ t2 + s[i];
            stk.push(ans);
        }
        
        return stk.top();
    }
};