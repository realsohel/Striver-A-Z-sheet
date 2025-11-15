#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token="";
        stack<string> stk;

        stringstream ss(path);
        while(getline(ss,token,'/')){
            if(token=="" or token=="."){
                continue;
            }
            else if(token!=".."){
                stk.push(token);
            }
            else if(!stk.empty()){
                stk.pop();
            }
        } 

        if(stk.empty())
            return "/";

        string res="";

        while(!stk.empty()){
            res = "/" + stk.top() + res;
            stk.pop();
        }

        return res;
    }
};