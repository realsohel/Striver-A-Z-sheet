#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:


// Approach 1  
    int n;
    void solve(vector<int> &temp, unordered_map<int,int> &mp, vector<vector<int>> &res){

        if(temp.size()==n){
            res.push_back(temp);
            return ;
        }

        for(auto&[num,freq]:mp){
            if(freq==0)
                continue;
            
            temp.push_back(num);
            freq--;

            solve(temp,mp,res);
            temp.pop_back();
            freq++;

        }
    }



    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> res;
        unordered_map<int,int> mp;
        vector<int> temp;
        
        for(int &x:nums)
            mp[x]++;

        solve(temp,mp,res);

        return res;

    }
};