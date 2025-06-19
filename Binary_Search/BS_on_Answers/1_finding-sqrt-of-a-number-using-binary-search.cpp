#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long floorSqrt(long long n)  {
        
        long long low =0, high = n;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            long long sq = mid*mid;

            if(sq==n)
                return mid;
            else if(sq > n){
                high=mid-1;
            }
            else  
                low=mid+1;
        }
        return high;
    }
};

int main() {
    Solution sol;
    long long n;
    cout << "Enter a number to find its square root: ";
    cin >> n;
    long long result = sol.floorSqrt(n);
    
    cout << "The floor of the square root of " << n << " is: " << result << endl;
    
    return 0;
}