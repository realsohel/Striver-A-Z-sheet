#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int via=0;via<n;via++){
            
            for(int i=0;i<n;i++){
                if(i==via)continue;
                
                for(int j=0;j<n;j++){
                    if(j==via || j==i)continue;
                    
                    if(dist[i][via]!=1e8 and dist[via][j]!=1e8 and 
                        (dist[i][via] + dist[via][j]) < dist[i][j]
                    )
                    
                    dist[i][j] = dist[i][via] + dist[via][j];
                }
            }
        }
    }
};