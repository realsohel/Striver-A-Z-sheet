#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;   // min-heap by card value
        }
    };

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int,int> freq;
        for (int x : hand) freq[x]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for (auto &it : freq) {
            pq.push({it.first, it.second});
        }

        while (!pq.empty()) {
            vector<pair<int,int>> temp;
            int start = pq.top().first;

            for (int i = 0; i < groupSize; i++) {
                if (pq.empty()) return false;

                auto cur = pq.top();
                pq.pop();

                if (cur.first != start + i) return false;

                cur.second--;
                if (cur.second > 0)
                    temp.push_back(cur);
            }

            for (auto &p : temp)
                pq.push(p);
        }

        return true;
    }
};
