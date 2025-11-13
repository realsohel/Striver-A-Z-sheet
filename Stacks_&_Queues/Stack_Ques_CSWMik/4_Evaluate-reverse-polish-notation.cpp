#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        if(tokens.size() < 3) return stoi(tokens[0]);
        stack<string>st;
        string check = "+ - * /";
        for(string c : tokens){
            if(check.find(c) == string::npos){
                st.push(c);
                continue;
            }
            int a = stoi(st.top());
            st.pop();
            int b = stoi(st.top());
            st.pop();
            ans = solver(b,a,c);
            // cout<<a<<" "<<b<<endl;
            st.push(to_string(ans));
        }  
        return ans;      
    }

    int solver(int &a , int &b , string &c){

        if(c == "+"){
            return a+b;
        }
        if(c == "*"){
            return a*b;
        }
        if(c == "-"){
            return a-b;
        }
        if(c == "/"){
            return a/b;
        }
        return a+b;
    }
};