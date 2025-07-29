#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Approach: Find the largest odd number in a string
// Time Complexity: O(n)
// Space Complexity: O(1)
    string largestOddNumber(string num) {
        int n = num.length();
        
        if((num[n-1]-'0')%2!=0)
            return num;

        for(int i=n-2;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }

        return "";
    }
};