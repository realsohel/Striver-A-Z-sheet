#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    vector<vector<int>> dp{2001,vector<int>(2001,-1)};

    bool solve(vector<int>& stones, int curr_stone_idx, int prev_jump){
        if(curr_stone_idx==n-1)
            return true;

        if(dp[curr_stone_idx][prev_jump] !=-1){
            return dp[curr_stone_idx][prev_jump];
        }

        bool res=false;

        for(int next_jump = prev_jump-1; next_jump<=prev_jump+1; next_jump++){
            if(next_jump > 0){
                int next_s = stones[curr_stone_idx] + next_jump;

                if(mp.find(next_s)!=mp.end()){
                    res = res || solve(stones, mp[next_s], next_jump);
                }
            }
        }

        return dp[curr_stone_idx][prev_jump] = res;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        if(stones[1]!=1)return false;

        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }    

        return solve(stones,0,0);
    }
};