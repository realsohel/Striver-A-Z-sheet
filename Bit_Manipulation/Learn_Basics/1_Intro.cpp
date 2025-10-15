#include <bits/stdc++.h>
using namespace std;

string toBinary(int n){
    string s ="";

    while(n>0){
        char ch = n%2 + '0';
        s = ch +s;
        n/=2;
    }

    return s;
}

int toDecimal(string s){
    int ans=0;
    
    int exp= s.size()-1;
    int p2=1;
    
    for(int i=s.size()-1;i>=0; i--){
        if(s[i]=='1')
            ans+= p2;
            
        p2 = p2 * 2;
    }
    
    return ans;
}

int main(){

    cout << toBinary(5555) << endl;
    cout << toDecimal("1101") << endl;
    
    cout << (13 >> 1) << endl;
    cout <<(  7 << 3) << endl;
    cout << (~5) << endl;
    cout << (~(-6)) << endl;
}