#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        int i=0,j=n-1;
        long long sum=0;
        
        while(k>0){
            
            while(pq1.size()<candidates and i<=j){
                pq1.push(costs[i]);
                i++;
            }

            while(pq2.size()<candidates and i<=j){
                pq2.push(costs[j]);
                j--;
            }

            int left = pq1.empty() ? INT_MAX : pq1.top();
            int right = pq2.empty() ? INT_MAX : pq2.top();

            if (left <= right) {
                sum += left;
                pq1.pop();
            } else {
                sum += right;
                pq2.pop();
            }
            k--;
        }


        return sum;
    }
};