#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans=0;

        for(int &x:piles){
            pq.push(x);
            ans+=x;
        }

        while(k>0 and !pq.empty()){
            int t = pq.top();
            pq.pop();
            
            pq.push(t-t/2);
            ans-=t/2;
            k--;
        }

        return ans;
    }
};

// ========================================= EXPLANATION =========================================
//
// Problem:
// You are given an array `piles`, where each element represents a pile of stones.
// You are allowed to perform exactly `k` operations.
//
// In one operation:
// → Choose the pile with the **maximum number of stones**
// → Remove ⌊pile / 2⌋ stones from it
//
// Goal:
// → Return the **minimum possible total number of stones** after `k` operations.
//
// -----------------------------------------------------------------------------------------------
// CORE IDEA
// -----------------------------------------------------------------------------------------------
//
// Always reduce the **largest pile first**.
//
// Why?
// - Removing half of a larger pile reduces more stones
// - Greedy choice guarantees minimum total sum
//
// To efficiently get the largest pile each time, we use a **max heap**.
//
// -----------------------------------------------------------------------------------------------
// DATA STRUCTURES USED
// -----------------------------------------------------------------------------------------------
//
// priority_queue<int> pq
// - Max heap
// - Always gives the pile with maximum stones in O(log N)
//
// ans
// - Stores the running total number of stones
//
// -----------------------------------------------------------------------------------------------
// STEP-BY-STEP WALKTHROUGH
// -----------------------------------------------------------------------------------------------
//
// FUNCTION: minStoneSum(vector<int>& piles, int k)
//

// Step 1: Initialize max heap and total sum
//
// for each pile in piles:
//     push pile into max heap
//     add pile to total sum (ans)
//
// This allows:
// - Fast access to the largest pile
// - Avoid recomputing sum every time
//


// Step 2: Perform k operations
//
// While:
// - we still have operations left (k > 0)
// - heap is not empty
//
// Do:
// 1. Take the largest pile
// 2. Remove floor(pile / 2) stones
// 3. Push the reduced pile back
// 4. Update total sum

// Step 3: Return result
//
// After k operations, ans holds the minimum possible
// total number of stones.