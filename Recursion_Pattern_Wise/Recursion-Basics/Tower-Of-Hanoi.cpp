#include<bits/stdc++.h> 
using namespace std;


// Print no. of Moves
int towerOfHanoi(int n, int from, int to, int aux) {
    // code here
    if(n==0)
        return 0;
    
    return pow(2,n)-1;
}