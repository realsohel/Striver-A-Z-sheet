#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int helper(vector<int> &arr, int pages){
        
        int stud=1;
        int pageCnt=0;
    
        for(int i=0; i<arr.size(); i++) {
            
            if(pageCnt+arr[i] <= pages){
                pageCnt+=arr[i];
            }
            else{
                stud++;
                pageCnt=arr[i];
            }
            
        }
        
        return stud;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        
        int low = *max(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        if(n<k)
            return -1;
        else if(n==k)
            return low;
            
        if(k==1)
            return high;
            
        
        while(low<=high){
            int mid = low + (high - low) / 2;
            
            int cntStud = helper(arr,mid);
            
            if(cntStud>k)
                low=mid+1;
            else
                high=mid-1;
        }
        
        return low;
        
        
    }
    
    
    int findPages1(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        
        int low = *max(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        if(n<k)
            return -1;
        else if(n==k)
            return low;
            
        if(k==1)
            return high;
            
        
            
        for(int pages = low ;pages<=high; pages++){
            
            int cntStud = helper(arr,pages);
            
            if (cntStud == k) {

                return pages;
            }
        }
        
        return -1;
        
        
    }

};