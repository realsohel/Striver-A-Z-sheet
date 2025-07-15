#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Since each row is sorted:

// 1. 0s appear first, then 1s

// 2. So, we can apply Binary Search on each row to find the first 1

// 3. Once we find the first 1, the number of 1s in that row = total_columns - index_of_first_1


    int chkCount(vector<int> a){
        int ans =-1;
        int m = a.size();
        
        int low=0,high=a.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(a[mid]==1){
                ans = m - mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
    }
    
    
// Optimal Approach
// Time Complexity: O(N*logM)
// Space Complexity: O(1)
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int ans = -1;
        int idx=-1;
        
        for(int i=0;i<n;i++){
            
            int cnt=chkCount(arr[i]);
            
            if(ans<cnt){
                ans=cnt;
                idx=i;
            }
        }
        
        return idx;
    }


//  Brute Force Approach
// Time Complexity: O(N*M)
// Space Complexity: O(1)
    int rowWithMax1s1(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int ans = -1;
        int idx=-1;
        
        for(int i=0;i<n;i++){
            int cnt=-1;
            
            for(int j=0;j<m;j++){
                if(arr[i][j]==1)
                    cnt++;
            }
            
            if(ans<cnt){
                ans=cnt;
                idx=i;
            }
        }
        
        return idx;
    }
};