#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimal Approach - Binary Search
// Time Complexity: O(log(m))
// Space Complexity: O(1)
    int nthRoot(int n, int m) {
        int low=1,high=m;
        
        
        while(low<=high){
            int mid= low+ (high-low)/2;
            int power = pow(mid,n);
            
            if(power==m)
                return mid;
            else if(power>m)
                high=mid-1;
            else
                low=mid+1;
            
        }
        return -1;
        
    }

// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
    int nthRoot1(int n, int m) {
        
        for(int i=1; i<=m; i++) {
            int ans = pow(i,n);
            if(ans == m) {
                return i;
            }
            if(ans > m) {
                break;
            }
        }

        return -1; // If no nth root found
    } 
};