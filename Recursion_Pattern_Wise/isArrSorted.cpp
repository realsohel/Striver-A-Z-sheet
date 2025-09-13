#include<bits/stdc++.h> 
using namespace std;

bool bS(vector<int>&a,int idx) {
    if(idx == a.size()-1)
        return true;
    
    if(a[idx]<=a[idx+1])
        return bS(a,idx+1);
    else 
        return false;
}   


int main(){

    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    cout << bS(a,0) << endl;;
    return 0;
}