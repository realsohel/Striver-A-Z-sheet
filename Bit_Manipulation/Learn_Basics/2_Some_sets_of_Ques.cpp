#include <bits/stdc++.h>
using namespace std;

// 2. Check if kth bit is set or not. 
bool checkKthBit(int n, int k) {
    return ((n>>k) & 1); // Right Shift
    return (n & (1<<k)); // Left Shift
}

// 3. Set the kth bit.
int setKthBit(int n, int k) {
    return n | (1<<k); // Left Shift
} 

// 4. Clear the kth bit.
int clearKthBit(int n, int k) {
    return n & ~(1<<k); // Left Shift
} 

// 5. Toggle the kth bit.
int toggleKthBit(int n, int k){
    return n^(1<<k);
}

// 6. Remove the last set bit.
int removeLastSetBit(int n){
    return n&(n-1);
}

// 7. is Power of 2.
bool isPowerofTwo(int n) { 
    if((n&(n-1))==0)
        return true;
    
    return false;
}

// 8. Swap 2 numbers. 
pair<int, int> Swap(int a, int b) {
    a^=b;
    b^=a;
    a^=b;
    
    return {a,b};
}

// 9. Count number of set bits.
int setBits(int n) {
    // Write Your Code here
    int cnt=0;

    while(n>0){
        cnt+= (n&1);
        n=n>>1;
    }

    return cnt;
}

int main(){

}