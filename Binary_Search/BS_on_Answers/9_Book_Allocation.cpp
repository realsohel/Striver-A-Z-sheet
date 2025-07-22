#include<bits/stdc++.h>
using namespace std;


// Answer: This problem is a classic application of binary search on the answer (search space).
// The task is to allocate books (represented by the array `arr`) to `k` students such that
// the **maximum number of pages assigned to any student is minimized**.
//
// Key Observations:
// - Every student gets a contiguous sequence of books.
// - We are trying to **minimize the maximum number of pages** any student has to read.
// - The minimum possible pages (low) is the maximum element in the array (since each student must get at least one book).
// - The maximum possible pages (high) is the sum of all pages (if one student gets all books).
//
// Approach (Binary Search):
// - Perform binary search on the range [max(arr), sum(arr)].
// - For a mid value (potential max pages per student), use the `helper()` function to check
//   how many students are needed if no student reads more than `mid` pages.
// - If more than `k` students are required, it means `mid` is too small → increase `low`.
// - Else, try to minimize further → decrease `high`.
//
// Helper Function – helper():
// - Simulates allocating books to students with the constraint that no student reads more than `pages`.
// - Iterates through the array and assigns pages to students greedily.
// - If the page count exceeds `pages`, we assign the current book to the next student and reset the page counter.
//
// Time Complexity: O(n * log(sum - max))
//   - n = number of books
//   - log(sum - max) = binary search range
//
// Space Complexity: O(1) – constant space used


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