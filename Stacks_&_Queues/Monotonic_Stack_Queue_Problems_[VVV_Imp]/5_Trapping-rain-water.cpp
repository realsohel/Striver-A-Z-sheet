#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// SOLVED BY OWN A TO Z. Every Logic by me !! Alhamdulillah
    vector<int> nextGtEqRight(vector<int> height){
        int n = height.size();
        vector<int> ans(n);
        stack<int> stk;

        for(int i=0;i<n;i++){

            while(!stk.empty() and height[i]>stk.top()){
                stk.pop();
            }

            if(stk.empty()){
                ans[i]=-1;
                stk.push(height[i]);
            }
            else{
                ans[i]=stk.top();
            }
            
        }

        return ans;
    }
    
    vector<int> nextGtEqLeft(vector<int> height){
        int n = height.size();
        vector<int> ans(n);
        stack<int> stk;

        for(int i=n-1;i>=0;i--){

            while(!stk.empty() and height[i]>stk.top()){
                stk.pop();
            }

            if(stk.empty()){
                ans[i]=-1;
                stk.push(height[i]);
            }
            else{
                ans[i]=stk.top();
            }
            
        }

        return ans;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> NGtEqLeft = nextGtEqLeft(height);
        vector<int> NGtEqRight = nextGtEqRight(height);

        int cnt=0;
        for(int i=0;i<n;i++){
            int val1 = NGtEqLeft[i];
            int val2 = NGtEqRight[i];

            if(val1 ==-1 or val2==-1)
                continue;
            
            cnt += (min(val1,val2) - height[i]);
        }

        return cnt;
    }
};