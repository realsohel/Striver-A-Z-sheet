#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countPairs(vector<int> &arr, int low,int mid,int high){
        int left = low;      
        int right = mid + 1; 
        int cnt =0;
        
        for(int i=low;i<mid;i++){
            while(right<=high && arr[i] > 2*arr[right]){
                right++;
            }
            cnt += (right - (mid + 1)); // count pairs
        }
        return cnt;
    }

    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

    

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt=0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        
        cnt+= mergeSort(arr, low, mid);  // left half
        cnt+= mergeSort(arr, mid + 1, high); // right half
        cnt += countPairs(arr, low, mid, high);  // count pairs in the merged array
        merge(arr, low, mid, high);  // merging sorted halves
        
        return cnt;
    }

    // ==================== Approach 2 ==================
// Time complexity: O(NlogN)
// Space complexity: O(N)
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    
    }

// ==================== Approach 1 ==================
// Time complexity: O(N^2) => TLE
// Space complexity: O(1)
    // int reversePairs(vector<int>& nums) {
    //     int n = nums.size();

    //     int ans =0;

    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             long long strt = nums[i];
    //             long long end = nums[j];
    //             end *=2;
    //             if(strt>end)
    //                 ans++;
    //         }
    //     }

    //     return ans;
    // }
};