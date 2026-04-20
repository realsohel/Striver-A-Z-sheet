#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [node, cnt] = q.front();
            q.pop();

            if (node == endWord) return cnt;

            for (int i = 0; i < node.size(); i++) {
                string temp = node;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.find(temp) != st.end()) {
                        q.push({temp, cnt + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};