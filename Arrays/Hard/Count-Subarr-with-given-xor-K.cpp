#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ======================================= OPTIMAL =======================================
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // This is a prefix XOR problem. We can use a hash map to store the frequency of prefix XOR values.
    int subarraysWithXorK(vector<int> &nums, int k) {
        
        unordered_map<int, int> mp;
        int ans = 0, cxor = 0;

        for(int i=0;i<nums.size();i++){
            cxor ^= nums[i];

            if(cxor == k) ans++;

            if(mp.find(cxor ^ k) != mp.end())
                ans += mp[cxor ^ k];

            mp[cxor]++;
        }
        return ans;
    }

// BRUTE FORCE
//     // Time Complexity: O(n^2)
//     // Space Complexity: O(1)
    // int subarraysWithXorK(vector<int> &nums, int k) {
    //     int ans = 0;
    //     int n = nums.size();

    //     for (int i = 0; i < n; i++) {
    //         int cxor = 0;
    //         for (int j = i; j < n; j++) {
    //             cxor ^= nums[j];
    //             if (cxor == k)
    //                 ans++;
    //         }
    //     }

    //     return ans;
    // }
};

int main() {
    
    Solution obj;
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Input array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nK: " << k << endl;
    cout << obj.subarraysWithXorK(nums, k) << endl;  // Output: 4
    return 0;
}
