#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long int  merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
        int cnt =0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // count inversions
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

        return cnt; 
    }

    long long int mergeSort(vector<int> &arr, int low, int high) {
        long long int cnt = 0;

        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt+= mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);  // merging sorted halves

        return cnt; 
    }

    long long int numberOfInversions(vector<int> nums) {
        
        int n = nums.size();
        return mergeSort(nums, 0, n - 1); 
    }

    
// Approach 1: Brute Force
// Time complexity: O(N^2)
// Space complexity: O(1)
    // long long int numberOfInversions(vector<int> nums) {
    //     int n = nums.size();
    //     long long int count = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]>nums[j])
    //                 count++;
    //         }
    //     }
    //     return count;
    // }

};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 8, 6, 1};
    cout << "Number of inversions: " << sol.numberOfInversions(nums) << endl;
    return 0;
}