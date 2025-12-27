#include <bits/stdc++.h>
using namespace std;

string isKSortedArray(int nums[], int n, int k) {

    vector<pair<int,int>> arr;

    for(int i = 0; i < n; i++) {
        arr.push_back({nums[i], i}); 
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(abs(arr[i].second - i) > k) {
            return "No";
        }
    }

    return "Yes";
}