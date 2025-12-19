// Link: https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }

        int i = 0, j = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (j < n) {
            if (mp[s[j]] > 0) {
                cnt++;
            }
            mp[s[j]]--;

            while (cnt == m) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
