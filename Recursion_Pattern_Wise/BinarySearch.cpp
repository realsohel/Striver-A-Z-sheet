#include<bits/stdc++.h> 
using namespace std;

bool bS(vector<int>&a,int target, int low,int high) {
    if(low>high)
        return false;
    
    int mid = low + (high-low)/2;

    if(a[mid]==target)
        return true;
    else if(a[mid]>target){
        return bS(a,target,low,mid-1);
    }
    else
        return bS(a,target,mid+1,high);
}   


int main(){

    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    cout << bS(a,4,0,a.size()-1) << endl;;
    return 0;
}