#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:

    void backTrack(int start,int n,int k, vector<int> &curr, vector<vector<int>> &res){

        if(k==0 ){
            res.push_back(curr);
            return;
        }

        for(int i=start;i<=n;i++){

            curr.push_back(i);

            backTrack(i+1, n,k-1,curr,res);

            curr.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        backTrack(1,n,k,curr,res);

        return res;
    }
};