#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        unsigned int xorr=0;
        
        for(int &x:arr){
            xorr^=x;
        }
        
        // int rightmost= (xorr&(xorr-1)) ^xorr;
        unsigned rightmost = xorr & -xorr;
        int b1=0,b2=0;
        
        for(int &x:arr){
            
            if(rightmost&x){
                b1^=x;        
            }
            else
                b2^=x;
        }
    
        
        if(b1>=b2){
            return {b1,b2};
        }
        
        return {b2,b1};
    }
};

int main(){
    return 0;
}