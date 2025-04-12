#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// ======================================= OPTIMAL =======================================
// Time Complexity: O(nlogn + n)
// Space Complexity: O(n)
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>> ans;
        sort(inter.begin(), inter.end());

        int n = inter.size();

        for(int i=0;i<n;i++){
            if(ans.empty() or inter[i][0]>ans.back()[1]){
                ans.push_back(inter[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], inter[i][1]);
            }
        }

        return ans;
    }

// ======================================= BRUTE FORCE =======================================
// Time Complexity:  O(nlogn + 2n)
// Space Complexity: O(1)
    // vector<vector<int>> merge(vector<vector<int>>& inter) {
    //     vector<vector<int>> ans;
    //     sort(inter.begin(), inter.end());

    //     int n = inter.size();
        
    //     for (int i = 0; i < inter.size(); i++) {
    //         int first = inter[i][0];
    //         int second = inter[i][1];

    //         if(!ans.empty() and second<=ans.back()[1])
    //             continue;

    //         for (int j = i + 1; j < inter.size(); j++) {
    //             if (second >= inter[j][0]) {
    //                 first = min(inter[i][0], inter[j][0]);
    //                 second = max(second, inter[j][1]);
    //             } else {
    //                 break;
    //             }
    //         }
    //         ans.push_back({first, second});
    //     }

    //     return ans;
    // }
    
};
    