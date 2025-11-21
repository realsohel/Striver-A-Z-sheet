#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

// Optimal
// TIME = O(2*N)
// SPACE = O(N)
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;

        for(int i=2*n-1;i>=0;i--){
            int val = nums[i%n];
            
            while(!stk.empty() and val>=stk.top())
                stk.pop();
            
            if(i<n){
                if(stk.empty())
                    ans[i]=-1;
                else
                    ans[i]=stk.top();
            }
            stk.push(val);
        }

        return ans;
    }

// Brute Force
// TIME = O(N*N)
// SPACE = O(N)
    vector<int> nextGreaterElements1(vector<int>& nums) {
        vector <int> newnums;
        for(int &x:nums){
            newnums.push_back(x);
        }
        for(int &x:nums){
            newnums.push_back(x);
        }
        int n = newnums.size();
        vector<int> ans;
        int maxi = *max_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(ans.size()==nums.size())
                break;
                
            int val = -1;
            if(newnums[i]==maxi){
                ans.push_back(val);
                continue;
            }

            for(int j=i+1; j<n;j++){
                if(newnums[j]>newnums[i]){
                    val=newnums[j];
                    break;
                }
            }
            

            ans.push_back(val);
        }

        return ans;
    }

};