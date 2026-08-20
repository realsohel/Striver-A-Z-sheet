#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    bool compare(string &s1, string &s2){
        if(s1.size() != (s2.size()+1)) return false;

        int f=0, s=0;

        while(f<s1.size()){
            if(s<s2.size() and s1[f]==s2[s]){
                f++;
                s++;
            }
            else{
                f++;
            }
        }

        if(f==s1.size() and s==s2.size())
            return true;
        
        return false;
    }

    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);

        vector<int> dp(n,1);
        int maxi=1;
        int lstIndx=0;
        
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx; prev++){

                if(compare(words[idx], words[prev]) and 1+ dp[prev] > dp[idx]){
                    dp[idx] =  1+dp[prev];
                }
            }
            
            if(dp[idx]>maxi){
                maxi = dp[idx];
            }
        }

        return maxi;
    }
};