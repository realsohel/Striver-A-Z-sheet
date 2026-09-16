#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
// OPTIMAL Approach - 
// TIME -> O(NLOGN)
// SPACE -> O(1)
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int i=0, j=0;
        int cnt=0,maxi=0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }    
            else{
                cnt--;
                j++;
            }
            
            maxi=max(maxi,cnt);
        }
        
        return maxi;
    }
  
//   BETTER Approach - 
// TIME -> O(NLOGN)
// SPACE -> O(2*N)
    int minPlatform2(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<pair<int,char>> vec;
        
        for(int &x:arr){
            vec.push_back({x,'A'});
        }
        
        for(int &x:dep){
            vec.push_back({x,'D'});
        }
        
        sort(vec.begin(),vec.end());
        
        int maxi=0;
        int cnt=0;
        
        for(int i=0;i<2*n;i++){
            if(vec[i].second=='A')
                cnt++;
            else
                cnt--;
            
            maxi=max(maxi,cnt);
        }
        
        return maxi;
        
    }
    
    
//   BRUTE FORCE - 
    int minPlatform1(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int maxi = 0;
    
        for (int i = 0; i < n; i++) {
            int cnt = 0;
    
            for (int j = 0; j < n; j++) {
                if (arr[j] <= arr[i] && arr[i] <= dep[j]) {
                    cnt++;
                }
            }
    
            maxi = max(maxi, cnt);
        }
    
        return maxi;
    }
};
