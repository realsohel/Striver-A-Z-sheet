#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:

    bool solve(string &s, string &p,int i,int j){
        if(j==p.size()){
            if(i==s.size())
                return true;
            else
                return false;
        }        

        bool firstP = i<s.size() and (p[j]==s[i] or p[j]=='.');

        if(p[j+1]=='*'){
            bool notTake = solve(s,p,i,j+2);

            bool take = firstP and solve(s,p,i+1,j);

            return take or notTake;
        }
        else{
            return firstP and solve(s,p,i+1,j+1);
        }

        return true;
    }
    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
};