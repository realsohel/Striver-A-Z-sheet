#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

// Optimal
// Time Complexity --> O(sqrt(N))
// Space Complexity --> O(1)
    vector<int> primeFac(int n) {
        vector<int>ans;
        
        for(int i=2;i<=sqrt(n);i++){
        
            if(n%i==0){
                ans.push_back(i);
                
                while(n%i==0){
                    n=n/i;
                }
            }
        }
        
        if(n!=1)
            ans.push_back(n);
        return ans;
    }

    // Time Complexity --> O(sqrt(N)*sqrt(N))
    // Space Complexity --> O(1)
    bool isPrime(int n){
        if(n<=1)
            return false;
        
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return false;
        }
        
        return true;
    }
    
    vector<int> primeFac(int n) {
        // code here
        vector<int> ans;
        
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(isPrime(i))
                    ans.push_back(i);
                
                if(n/i !=i){
                    if(isPrime(n/i))
                        ans.push_back(n/i);
                }
            }
        }
        
        return ans;
    }
};