// Link - https://leetcode.com/problems/lemonade-change
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// OPTIMAL
// TIME => O(N)
// SPACE=> O(1)
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        if(bills[0]!=5)
            return false;

        int fcnt=1, tcnt=0, twcnt=0;
        
        for(int i=1;i<n;i++){
            if(bills[i]==5)
                fcnt++;
            
            if(bills[i]==10){
                if(fcnt==0)
                    return false;
                tcnt++;
                fcnt--;
            }

            if(bills[i]==20){
                if (tcnt >= 1 && fcnt >= 1) {
                    // give 10 + 5
                    tcnt--;
                    fcnt--;
                }
                else if (fcnt >= 3) {
                    // give 5 + 5 + 5
                    fcnt -= 3;
                }
                else {
                    return false;
                }
                twcnt++;
            }

        }

        return true;
    }
};