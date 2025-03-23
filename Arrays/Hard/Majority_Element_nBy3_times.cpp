#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //  Optimal Approach - Moore's Voting Algorithm
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 =0, cnt2=0;
        int e1,e2;

        int n = nums.size();

        for(int x:nums){
            if(cnt1==0 and x!=e2){
                cnt1++;
                e1=x;
            }
            else if(cnt2==0 and x!=e1){
                cnt2++;
                e2=x;
            } 
            else if(x==e1)
                cnt1++;
            else if (x==e2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int chk1=0, chk2=0;

        for(int x:nums){
            if(x==e1)
                chk1++;
            else if(x==e2)
                chk2++;
        }

        if(chk1>n/3 and chk2>n/3)
            return {e1,e2};
        else if(chk1>n/3 and chk2<=n/3)
            return {e1};
        else if(chk1<=n/3 and chk2>n/3)
            return {e2};

        return {};
    }

    // Better Approach
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     n /=3;

    //     unordered_map<int,int>mp;
    //     vector<int> ans;

    //     for(int x:nums)
    //         mp[x]++;

    //     for(auto m:mp){
    //         if(m.second>n)
    //             ans.push_back(m.first);
    //     }

    //     return ans;
    // }
};