#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:

    void solve(int n, string &s, vector<string> &res, int open, int close){

        if(s.length()==2*n){
            res.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            solve(n,s,res,open+1,close);
            s.pop_back();
        }

        if(close<open){
            s.push_back(')');
            solve(n,s,res,open,close+1);
            s.pop_back();
        }


    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        solve(n,s,res,0,0);

        return res;
    }


    // bool isValid(string s){
    //     int cnt=0;

    //     for(char &ch:s){
    //         if(ch=='(')
    //             cnt++;
    //         else
    //             cnt--;

    //         if(cnt<0)
    //             return false;
    //     }

    //     return cnt==0;
    // }

    // void solve(int n, string &s, vector<string> &res){

    //     if(s.length()==2*n){
    //         if(isValid(s))
    //             res.push_back(s);
            
    //         return;
    //     }

    //     s.push_back('(');
    //     solve(n,s,res);
    //     s.pop_back();

    //     s.push_back(')');
    //     solve(n,s,res);
    //     s.pop_back();

    // }

    // vector<string> generateParenthesis(int n) {
    //     vector<string> res;
    //     string s="";
    //     solve(n,s,res);

    //     return res;
    // }
};