#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    int subs = 1<<n;

    for(int i=0;i<subs;i++){
        vector<int> subset;

        for(int j=0;j<n;j++){

            if(i&(1<<j)){
                subset.push_back(nums[j]);
            }
        }

        res.push_back(subset);
    }
    return res;
}

int main(){
    return 0;
}