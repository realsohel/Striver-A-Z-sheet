#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prof=0, minPrice = INT_MAX;

        for(int i=0;i<n;i++){
            int cost = prices[i] - minPrice;
            prof=max(prof,cost);
            
            minPrice = min(prices[i],minPrice);
        }

        return prof;

    }
};