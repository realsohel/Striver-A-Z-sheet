// Link: https://leetcode.com/problems/longest-repeating-character-replacement/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// OPTIMAL APPROACH
// T.C => O(N)
// S.C => O(26)
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i=0,j=0;
        int maxi=0;
        unordered_map<int,int> mp;
        int maxFreq=0;

        while(j<n and i<n){
            mp[s[j]]++;
            maxFreq=max(maxFreq,mp[s[j]]);

            if((j-i+1)-maxFreq>k and i<n){
                mp[s[i]]--;
                maxFreq=max(maxFreq,mp[s[j]]);
                i++;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }

// BETTER APPROACH
// T.C => O(2N)
// S.C => O(26)
    int characterReplacement1(string s, int k) {
        int n = s.length();
        int i=0,j=0;
        int maxi=0;
        unordered_map<int,int> mp;
        int maxFreq=0;

        while(j<n and i<n){
            mp[s[j]]++;
            maxFreq=max(maxFreq,mp[s[j]]);

            while((j-i+1)-maxFreq>k and i<n){
                mp[s[i]]--;
                maxFreq=max(maxFreq,mp[s[j]]);
                i++;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};
