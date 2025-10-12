#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    void backTrack(vector<int>& nums, int idx, vector<int> &curr, vector<vector<int>> &res){

        if(curr.size()>=2){
            res.push_back(curr);
        }

        unordered_set<int> st;

        for(int i=idx; i<nums.size();i++){

            // Do
            if((curr.empty() || nums[i]>=curr.back()) and st.find(nums[i])==st.end() ){
                curr.push_back(nums[i]);

                // Explore
                backTrack(nums,i+1,curr,res);

                // Undo
                curr.pop_back();
                st.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        backTrack(nums,0,curr,res);

        return res;
    }
};