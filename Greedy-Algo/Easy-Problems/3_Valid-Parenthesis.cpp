#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    bool checkValidString(string s) {
        int n = s.length();
        int mini=0, maxi=0;

        for(int i=0;i<n;i++){

            if(s[i]=='('){
                mini=mini+1;
                maxi=maxi+1;
            }
            else if(s[i]==')'){
                mini=mini-1;
                maxi=maxi-1;
            }
            else {
                mini=mini-1;
                maxi=maxi+1;
            }

            if(mini<0)
                mini=0;
            
            if(maxi<0)
                return false;
        }

        return mini==0;
    }

// USING DP 
// TIME = O(N*N)
// SPACE = O(N*N)
    bool solve(string &s, int idx, int n, int cnt, vector<vector<int>> &dp){
        if(cnt<0)
            return false;
        
        if(idx>=n){
            return cnt==0;
        }
        if(dp[idx][cnt]!=-1)
            return dp[idx][cnt];

        if(s[idx]=='(')
            return dp[idx][cnt] = solve(s,idx+1, n, cnt+1, dp);
        if(s[idx]==')')
            return dp[idx][cnt] = solve(s,idx+1, n, cnt-1, dp);
        
        return dp[idx][cnt] = (solve(s,idx+1,n,cnt+1, dp) || solve(s,idx+1,n,cnt-1, dp) || solve(s,idx+1,n,cnt, dp) ); 
    }

    bool checkValidString1(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));

        return solve(s,0,n,0, dp);
    }
};