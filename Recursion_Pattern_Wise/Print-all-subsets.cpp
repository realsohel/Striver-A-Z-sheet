#include<bits/stdc++.h> 
using namespace std;

void printSubsets(vector<int>&a,vector<int>ans, int i){
    if(i==a.size()){
        for(int x:ans){
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(a[i]); // include
    printSubsets(a,ans,i+1); // include  

    ans.pop_back();
    printSubsets(a,ans,i+1); // exclude;
}

int main(){

    vector<int> a = {1,2,3};

    printSubsets(a,{},0);
    return 0;
}


class Solution {
public:
    void printSubsets(vector<int>&a,vector<int>&ans, vector<vector<int>>&res, int i){
        if(i==a.size()){
            res.push_back(ans);
            return;
        }
        ans.push_back(a[i]); // include
        printSubsets(a,ans,res,i+1); // include  

        ans.pop_back();
        printSubsets(a,ans,res,i+1); // exclude;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;

        printSubsets(nums,ans,res,0);
        return res;
    }
};