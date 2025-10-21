#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    // O(1)
    int xorFunc(int n){
        if(n%4==0){
            return n;
        }
        if(n%4==1){
            return 1;
        }
        if(n%4==2){
            return n+1;
        }
        
        return 0;
    }
    
    int findXOR(int l, int r) {
        
        return xorFunc(l-1)^xorFunc(r);
    }
    
// TLE
    int findXOR1(int l, int r) {
        int ans=0;
        for(int i=l;i<=r;i++){
            ans^=i;
        }
        
        return ans;
    }
};