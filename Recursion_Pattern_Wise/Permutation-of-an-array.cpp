#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:

    void getPer(vector<int>& nums, vector<vector<int>> & ans, int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){

            swap(nums[idx],nums[i]); // do
            getPer(nums,ans,idx+1);
            swap(nums[idx],nums[i]); // undo
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPer(nums,ans,0);

        return ans;    
    }

    
    unordered_set<int> st;

    void solve(vector<int>& temp, vector<int>& nums, vector<vector<int>> &res){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp,nums,res);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }

    }
    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(temp,nums, res);

        return res;
    }
};