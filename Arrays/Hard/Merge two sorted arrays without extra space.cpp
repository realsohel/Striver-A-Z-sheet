#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// ==================== Approach 1 ==================
// Time complexity: O((M+N) + Log(M+N))
// Space complexity: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =0;
        for(int j=m;j<m+n; j++){
            nums1[j]=nums2[i];
            i++;
        }

        sort(nums1.begin(),nums1.end());
    }
};