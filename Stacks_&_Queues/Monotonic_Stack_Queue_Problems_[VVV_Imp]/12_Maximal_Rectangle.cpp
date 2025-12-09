#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxi=0;

        for(int i=0;i<n;i++){
            while(!stk.empty() and heights[i]<heights[stk.top()]){
                int el = heights[stk.top()];
                stk.pop();
                int nse= i;
                int pse= stk.empty() ? -1:stk.top();
                
                maxi = max(maxi, el*(nse-pse-1));
            }

            stk.push(i);
        }

        while(!stk.empty()){
            int el = heights[stk.top()];
            stk.pop();
            int nse= n;
            int pse= stk.empty() ? -1:stk.top();
                
            maxi = max(maxi, el*(nse-pse-1));
        }

        return maxi;
    }

// OPTIMAL
// T.C => O(M*N) + O((2*M) * N)
// S.C => O(N*M)
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefSum(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int cnt =0;
            for(int i=0;i<n;i++){
                if(mat[i][j]=='1'){
                    cnt++;
                }
                else{
                    cnt=0;
                }
                prefSum[i][j]=cnt;
            }
        }

        int maxi=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi,largestRectangleArea(prefSum[i]));
        }

        return maxi;
    }
};