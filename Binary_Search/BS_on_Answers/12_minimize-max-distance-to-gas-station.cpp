#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// Optimal Approach - Using Binary Search
// IT IS IN TO DO, I'LL SOLVE IT LATER !!
    double findSmallestMaxDist1(vector<int> &arr, int k) {
        return 0.0;
    }

// Best Approach
// Time Complexity: O(n * log(n) + k * log(n))
// Space Complexity: O(n-1) ~ O(n)
// This approach uses a priority queue to efficiently manage the distances between gas stations.
    double findSmallestMaxDist1(vector<int> &arr, int k) {
        // Code here
        
        int n = arr.size();
        vector<int> howMany(n-1,0);
        priority_queue<pair<double,int>> pq;
        
        for(int i=0;i<n-1;i++){
            pq.push({arr[i+1]-arr[i],i});
        }
        
        
        for(int gas=1; gas<=k;gas++){
            auto tp = pq.top();
            pq.pop();
            
            int indx = tp.second;
            howMany[indx]++;   
            
            double diff =  arr[indx+1] - arr[indx];
            double newSec = diff / (double)(howMany[indx]+1);
            
            pq.push({newSec,indx});
            
        }
        
        return round(pq.top().first * 100.0) / 100.0;

    }



// Brute Force Approach
// Time Complexity: O(k * n) + O(n)
// Space Complexity: O(1)
// TLE hits !!
    double findSmallestMaxDist2(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n-1,0);
        
        for(int gas=1; gas<=k;gas++){
            double maxVal =-1;
            int maxIndx = -1;
            
            for(int i=0;i<n-1;i++){
                double diff = arr[i+1]-arr[i];
                double section = diff/((double)howMany[i]+1);
                
                if(maxVal<section){
                    maxVal=section;
                    maxIndx=i;
                }
            }
            howMany[maxIndx]++;      
        }
        
        double ans = -1;
        
        for(int i=0;i<n-1;i++){
            double section = (arr[i+1] - arr[i])/(double)(howMany[i]+1);
            ans=max(ans,section);
        }
        
        return ans;
    }
};