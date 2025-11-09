#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPrefix(string &s) {
        // code here
        string ans = "";
        stack<char> st;
        
        int i=s.size()-1;
        
        unordered_map<char, int> priority;
        priority['^'] = 3;
        priority['/'] = 2;
        priority['*'] = 2;
        priority['+'] = 1;
        priority['-'] = 1;
        
        while(i>=0){
            if(s[i]=='^' || s[i]=='/' || s[i]=='*' || s[i]=='+' || s[i]=='-'){
                if(s[i]=='^'){
                    while(!st.empty() && st.top()!=')' && priority[st.top()] >= priority[s[i]]){
                        ans += st.top();
                        st.pop();
                    }
                
                }
                else {
                    while(!st.empty() && st.top()!=')' && priority[st.top()] > priority[s[i]]){
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
            else if(s[i]=='('){
                while(st.top() != ')'){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]==')')
                st.push(s[i]);
            else
                ans+=s[i];
            
            i--;  
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


