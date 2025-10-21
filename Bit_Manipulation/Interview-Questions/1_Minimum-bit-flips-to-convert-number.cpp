#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;

        while(start>0 and goal>0){
            int r1 = start%2;
            int r2 = goal%2;

            if(r1!=r2)
                cnt++;

            start=start>>1;
            goal=goal>>1;
        }

        int stcount=0;

        while(start>0){
            stcount+= (start&1);
            start=start>>1;
        }

        while(goal>0){
            stcount+= (goal&1);
            goal=goal>>1;
        }

        return cnt+ stcount;
    }
};