#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size()==0)
            return res;
        
        for(int i=0;i<strs[0].size();i++){
            for(auto j:strs){
                if(j[i]!=strs[0][i])
                    return res;
            }
            res+=strs[0][i];
        }
        return res;

    }
};