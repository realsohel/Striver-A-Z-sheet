#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

// Optimal
// Time => O(n + n*log(logn))
// Space => O(1)
    int countPrimes(int n) {
        
        vector<int> prime(n+1,1);
        int cnt=0;

        for(int i=2;i<=sqrt(n);i++){
            if(prime[i]==1){

                for(int j=i*i; j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }

        for(int i=2;i<n;i++){
            cnt+=prime[i];
        }

        return cnt;
    }



    bool isPrime(int n){
        if(n<=1)
            return 0;
        
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return 0;
        }

        return 1;
    }


    // TLE
    int countPrimes(int n) {
        int cnt=0;

        for(int i=1;i<n;i++){
            if(isPrime(i))
                cnt++;
        }

        return cnt;
    }
};