#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// OPTIMAL
// T.C => O(2N)
// S.C => O(N)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxi=0;

        for(int i=0;i<n;i++){
            while(!stk.empty() and heights[i]>=heights[stk.top()]){
                int el = heights[stk.top()];
                int nse= i;
                int pse= stk.empty() ? -1:stk.top();
                stk.pop();
                
                maxi = max(maxi, el*(nse-pse-1));
            }

            stk.push(i);
        }

        while(!stk.empty()){
            int el = heights[stk.top()];
            int nse= n;
            int pse= stk.empty() ? -1:stk.top();
            stk.pop();
                
            maxi = max(maxi, el*(nse-pse-1));
        }

        return maxi;
    }

// BRUTE FORCE 
// T.C => O(5N)
// S.C => O(4N)
    vector<int> NSEIdx(vector<int> &arr,int n){
        vector<int> ans(n);
        stack<int> stk;

        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and arr[stk.top()] >=arr[i]){
                stk.pop();
            } 
            
            if(stk.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=stk.top();
            }

            stk.push(i);
        }

        return ans;
    }

    vector<int> PSEIdx(vector<int> &arr, int n) {
        vector<int> pse(n);
        stack<int> stk; 

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                pse[i] = -1;
            } 
            else {
                pse[i] = stk.top();  
            }

            stk.push(i);
        }

        return pse;
    }

    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = NSEIdx(heights,n);
        vector<int> pse = PSEIdx(heights,n);
        
        int maxi=0;

        for(int i=0;i<n;i++){
            int area = heights[i] * (nse[i]-pse[i] - 1);
            maxi = max(maxi,area);
        }

        return maxi;
    }
};