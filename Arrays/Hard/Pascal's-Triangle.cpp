#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    
    long long res =1;

    for(int i=0;i<r;i++){

        res=res*(n-i);
        res=res/(i+1);

    }

    return res;
}

// Q1. Given R and C. Find the element at (R,C)th position in Pascal Triangle.

int atRC(int r, int c){
    r--;
    c--;

    return nCr(r,c);
}

// Q2. To print the N-th row of Pascal Triangle.

vector<int> nthRow(int n){
    vector<int> res;

    for(int i=0;i<n;i++){
        res.push_back(nCr(n-1,i));
    }

    return res;
}



int main(){
    cout << "Hello bhai" << endl;

    int ans =  atRC(6,3);
    cout << "ans: " << ans <<  endl;

    vector<int> res = nthRow(5);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }

    return 0;
}