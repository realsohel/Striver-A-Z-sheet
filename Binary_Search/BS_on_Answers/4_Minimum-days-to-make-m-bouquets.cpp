#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(vector<int>& bloomDay, int day,int k){
        int count =0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)
                count++;
            else{
                ans+= (count/k);
                count=0;
            }
        }

        ans+= (count/k);

        return ans;
    }

    // Binary Search Approach
    // Time Complexity: O(n * log(max - min))
    // Space Complexity: O(1)
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long cond = (long long)m*k;
        if(n<cond)
            return -1;
        
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int result =-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            int chk = helper(bloomDay,mid,k);

            if(chk>=m){
                result = mid;
                high = mid - 1;
            }
            else
                low=mid+1;
        }
        

        return result;
    }


// Brute Force Approach - Linear Search
// Time Complexity: O(n * (max - min))
// Space Complexity: O(1)
    int minDays1(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n<m*k)
            return -1;
        
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());

        for(int i=mini;i<=maxi;i++){
            int chk = helper(bloomDay,i,k);

            if(chk>=m)
                return i;
        }

        return -1;
    }
};