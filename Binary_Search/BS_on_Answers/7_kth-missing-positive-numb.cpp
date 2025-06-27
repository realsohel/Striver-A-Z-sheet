#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// ====================================== OPTIMAL APPROACH ========================================
// Time Complexity: O(logn)
// Space Complexity: O(1)

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        if(n == arr[n-1])
            return arr[n-1] + k;
        
        if(k<arr[0])
            return k;
        

        int low =1, high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            int missing = arr[mid] - (mid+1);

            if(missing <k)
                low=mid+1;
            else
                high=mid-1;
        }


        return low+k;
    }

// ====================================== Better APPROACH ========================================
// Time Complexity: O(n)
// Space Complexity: O(1)

    int findKthPositive1(vector<int>& arr, int k) {
        int n = arr.size();

        if(n == arr[n-1])
            return arr[n-1] + k;

        for(int i=0;i<n;i++){
            if(arr[i]<=k)
                k++;
            else
                break;

        }

        return k;
    }


// ====================================== BRUTAL FORCE APPROACH ========================================
// Time Complexity: O(n*(n_size + k))
// Space Complexity: O(1)

    bool isMissing(vector<int>& arr, int num){

        for(int i=0;i<arr.size();i++){
            if(arr[i]==num)
                return false;
        }

        return true;
    }

    int findKthPositive2(vector<int>& arr, int k) {
        int n = arr.size();

        if(n == arr[n-1])
            return arr[n-1] + k;
        

        int start =1, last = arr[n-1]+k;

        for(int i=start;i<=last;i++){
            bool miss = isMissing(arr,i);

            if(miss)
                k--;
            
            if(k==0)
                return i;
        }

        return -1;
    }
};