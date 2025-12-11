// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// OPTIMAL
// T.C => O(2N)
// S.C => O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k==n){
            return accumulate(cardPoints.begin(),cardPoints.end(),0);
        }
        int front=0,back=0;
        int maxi=0;

        for(int i=0;i<k;i++){
            front+=cardPoints[i];
        }
        
        maxi=front;
        for(int j=n-1;j>=0 and k>0;j--){
            front-=cardPoints[k-1];
            back+=cardPoints[j];
            maxi=max(maxi,front+back);
            k--;
        }
            
        return maxi;
    }
};