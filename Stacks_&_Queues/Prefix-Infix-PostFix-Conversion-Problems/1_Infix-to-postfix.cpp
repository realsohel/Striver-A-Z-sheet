#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int priority(char ch) {
        if (ch == '^')
            return 3;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }

    string infixToPostfix(string &s) {
        stack<char> stk;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isalpha(c)) {
                ans += c;
            }
            else if(c>='0' and c<='9')
                ans += c;
            else if (c == '(') {
                stk.push(c);
            }
            else if (c == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    ans += stk.top();
                    stk.pop();
                }
                if (!stk.empty())
                    stk.pop(); // remove '('
            }
            else { // operator
                while (!stk.empty() && priority(c) <= priority(stk.top()) && c != '^') {
                    ans += stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }

        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }

};
