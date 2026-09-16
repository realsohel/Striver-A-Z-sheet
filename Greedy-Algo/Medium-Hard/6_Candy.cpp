#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
// APPROACH 3 - 
//  TIME --> O(N)
//  SPACE--> O(1)
int candy(vector<int>& ratings) {
    int n = ratings.size();

    if (n <= 1)
        return n;

    int i = 1;
    int ans = 1;

    while (i < n) {

        // Equal ratings
        if (ratings[i] == ratings[i - 1]) {
            ans += 1;
            i++;
            continue;
        }

        int up = 0;
        int down = 0;

        // Increasing slope
        while (i < n && ratings[i] > ratings[i - 1]) {
            up++;
            i++;
        }

        // Decreasing slope
        while (i < n && ratings[i] < ratings[i - 1]) {
            down++;
            i++;
        }

        // Mountain contribution
        ans += 1LL * up * (up + 1) / 2;
        ans += 1LL * down * (down + 1) / 2;

        ans += max(up, down);
    }

    return ans;
}

// APPROACH 2 - 
//  TIME --> O(2*N)
//  SPACE--> O(N)
    int candy3(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,0);

        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]= left[i-1] + 1 ;
            }
            else{
                left[i]=1;
            }
        }

        int curr=1, prev=1;
        int totCnt=max(1, left[n-1]);

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                curr=prev+1;
                prev=curr;
            }
            else{
                curr=1;
                prev=1;
            }

            totCnt+= max(curr,left[i]);
        }

        return totCnt;
    }
// APPROACH 1 - 
//  TIME --> O(3*N)
//  SPACE--> O(2*N)
    int candy2(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,0);
        vector<int> right(n,0);

        left[0]=1;
        right[n-1]=1;

        int prev=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                prev++;
                left[i]=prev;
            }
            else{
                prev=1;
                left[i]=prev;
            }
        }

        prev=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                prev++;
                right[i]=prev;
            }
            else{
                prev=1;
                right[i]=prev;
            }
        }

        int totCnt=0;
        for(int i=0;i<n;i++){
            totCnt+= max(left[i],right[i]);
        }

        return totCnt;
    }

// Tried But Failed
    int candy1(vector<int>& ratings) {
        int n = ratings.size();

        int prev=0, totCnt=0;
        if(ratings[0]>ratings[1]){
            totCnt+=2;
            prev=2;
        }
        else{
            totCnt+=1;
            prev=1;
        }

        for(int i=1;i<n-1;i++){
            if(ratings[i]>ratings[i-1] or ratings[i]>ratings[i+1]){
                totCnt+=prev+1;
                prev++;
            }
            else{
                totCnt+=1;
                prev=1;
            }
        }

        if(ratings[n-1]>ratings[n-2]){
            totCnt+=prev+1;
        }
        else{
            totCnt++;
        }

        return totCnt;
    }
};