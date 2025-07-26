#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// Approach: Using Two Pointers to remove outermost parentheses
// Time Complexity: O(n)
// Space Complexity: O(n) for the result string else O(1)
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        
        for(int i=n-1;i>=0;i--) {
            if(s[i] == ' ') continue; // Skip spaces
            
            string word = "";
            // Extract the word
            while(i >= 0 && s[i] != ' ') {
                word = s[i] + word; // Prepend to reverse the word
                i--;
            }
            
            if(!result.empty()) 
                result += " "; // Add space before the next word
            
            result += word; // Append the reversed word
        }

        return result;
    }

// Approach: Using Stack to reverse words in a string
// Time Complexity: O(n)
// Space Complexity: O(n) for the stack
    string reverseWords1(string s) {
        stack<string> stk;
        string word = "";
        
        // Traverse the string to extract words
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    stk.push(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        // Push the last word if exists
        if (!word.empty()) 
            stk.push(word);

        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
            if (!stk.empty()) 
                result += " ";
        }

        return result;
    }
};
