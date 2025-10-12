#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:

    bool isPalindrome(string s){
        string t= s;
        reverse(s.begin(),s.end());
        return t==s;
    }

    void backTrack(string s, int idx, vector<string> &curr, vector<vector<string>> &res){

        if(idx==s.length()){
            res.push_back(curr);
        }

        for(int i=idx;i<s.size(); i++){

            if(isPalindrome(s.substr(idx,i-idx+1))){
                curr.push_back(s.substr(idx,i-idx+1));

                backTrack(s,i+1,curr,res);
                curr.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        backTrack(s,0,curr,res);  

        return res;
    }
};