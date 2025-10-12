#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    string findFromMap(char ch){
        unordered_map<char,string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        return mp[ch];
    }

    void backTrack(int idx,string &s,string &temp, vector<string> &res){

        if(idx>=s.length()){
            res.push_back(temp);
            return ;
        }

        string str = findFromMap(s[idx]);

        for(int i=0;i<str.length();i++){
            
            temp.push_back(str[i]);

            backTrack(idx+1,s,temp,res);

            temp.pop_back();
        }
    
    }


    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        
        vector<string> res;
        string temp="";

        backTrack(0,digits,temp,res);

        return res;
    }
};