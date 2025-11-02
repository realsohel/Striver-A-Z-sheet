#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isOpen(char ch){
        return ch=='(' or ch=='[' or ch=='{';
    }

    bool isValid(string s) {
        stack<char> stk;

        for(int i=0;i<s.length();i++){
            if(isOpen(s[i]))
                stk.push(s[i]);
            else{
                char top = stk.empty()==true ? 'N' : stk.top();
                if(s[i]==')' and top!='(')  
                    return false;
                else if(s[i]==']' and top!='[')  
                    return false;
                else if(s[i]=='}' and top!='{')
                    return false;
                else
                    stk.pop();
            }
        }

        return stk.empty();
    }
};