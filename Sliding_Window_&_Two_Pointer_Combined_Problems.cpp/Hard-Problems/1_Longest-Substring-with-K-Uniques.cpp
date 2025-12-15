// Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// OPTIMAL 
// T.C => O(N)
// S.C => O(26)
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxi=0;
        
        while(j<n and i<n){
            mp[s[j]]++;
            
            while(mp.size()>k){
                mp[s[i]]--;
                
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i++;
            }
            
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        if(mp.size()<k)
            return -1;
        
        return maxi;
        
    }

// BETTER  
// T.C => O(2N)
// S.C => O(26)
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxi=0;
        
        while(j<n and i<n){
            mp[s[j]]++;
            
            if(mp.size()>k){
                mp[s[i]]--;
                
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i++;
            }
            
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        if(mp.size()<k)
            return -1;
        
        return maxi;
        
    }
};