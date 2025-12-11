#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// OPTIMAL
// T.C => O(N)
// S.C => O(N)
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<int> st;

        int i=0,j=0;
        int maxi=0;

        while(j<n and i<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
            }
            else{
                maxi = max(maxi,j-i);
                st.erase(s[i]);
                i++;
            }

        }

        maxi = max(maxi,j-i);

        return maxi;
    }   
};