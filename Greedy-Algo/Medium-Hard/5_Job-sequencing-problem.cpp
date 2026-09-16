#include <bits/stdc++.h> 
using namespace std;

class Solution {
  public:

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int maxi = *max_element(deadline.begin(), deadline.end());
        vector<pair<int,int>> vec;
        vector<int> jobs(maxi+1,-1);
        
        for(int i = 0; i < n; i++){
            vec.push_back({profit[i], deadline[i]});    
        }

        sort(vec.begin(), vec.end(), greater<pair<int,int>>());
        
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int dead=vec[i].second;
            
            for(int idx =dead;idx>0;idx--){
                if(jobs[idx]==-1){
                    ans+=vec[i].first;
                    jobs[idx] = vec[i].first;
                    cnt++;
                    break;
                }
            }
        }
        
        return {cnt,ans};
    }
    

    
//   TRIED BUT FAILED
    vector<int> jobSequencing1(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int maxi = *max_element(deadline.begin(), deadline.end());
        vector<pair<int,int>> vec;

        for(int i = 0; i < n; i++){
            vec.push_back({deadline[i], profit[i]});    
        }

        sort(vec.begin(), vec.end(), greater<pair<int,int>>());

        
        int cntJob=maxi;
        int cnt=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(cntJob<=0)
                break;
            
            ans+=vec[i].second;
            cntJob = min(cntJob-1, vec[i].first-1);
            // cout << ans << " " << cntJob << " "; 
            cnt++;
        }
        
        return {cnt, ans};
        
        
    }
};