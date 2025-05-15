#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// Approach 2: Using Lower Bound and Upper Bound
// Time Complexity: O(2*logN) ~~ O(logN)
// Space Complexity: O(1)
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low=0,high =n-1;
        int ans=n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>=target){
                ans = mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        
        return ans;
    }


    int upperBound(vector<int>& arr, int target) {

        // code here
        int n = arr.size();
        int low=0,high =n-1;
        int ans=n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>target){
                ans = mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        
        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
    
        int n = arr.size();

        if(n==0)
            return 0;
        else if(n==1 ){
            if(arr[0]==target)
                return 1;
            else
                return 0;
        }

        int lb = lowerBound(arr,target);
        if(lb==n or arr[lb]!=target)
            return 0;
            
        int ub = upperBound(arr,target);

        
        return ub-1-lb+1;
    }

// Approach 1: 
// Time Complexity: ~~ O(N)
// Space Complexity: O(1)
    // int countFreq(vector<int>& arr, int target) {
    //     // code here
    //     int n = arr.size();
    //     int cnt=0;
        
    //     int low=0,high=n-1;
    //     while(low<=high){
    //         int mid = low+(high-low)/2;
            
    //         if(arr[mid]==target){
    //             cnt++;
    //             int left=mid-1,right=mid+1;
                
    //             while(target==arr[left]){
    //                 cnt++;
    //                 left--;
    //             }
                
    //             while(target==arr[right]){
    //                 cnt++;
    //                 right++;
    //             }
    //             break;
    //         }
    //         else if(target>arr[mid]){
    //             low=mid+1;
    //         }
    //         else
    //             high=mid-1;
    //     }
        
    //     return cnt;
    // }
};