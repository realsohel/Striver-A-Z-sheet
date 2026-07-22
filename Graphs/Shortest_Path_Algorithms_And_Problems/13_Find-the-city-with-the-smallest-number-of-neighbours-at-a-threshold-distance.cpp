#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n, vector<int>(n,INT_MAX));

        for(auto &e:edges){
            adjMat[e[0]][e[1]] = e[2];
            adjMat[e[1]][e[0]] = e[2];
        }

        for(int i=0;i<n;i++) adjMat[i][i]=0;

        for(int via=0;via<n;via++){
            
            for(int i=0;i<n;i++){
                if(i==via)continue;
                
                for(int j=0;j<n;j++){
                    if(j==via || j==i)continue;
                    
                    if(adjMat[i][via]!=INT_MAX and adjMat[via][j]!=INT_MAX and 
                        (adjMat[i][via] + adjMat[via][j]) < adjMat[i][j]
                    )
                    
                    adjMat[i][j] = adjMat[i][via] + adjMat[via][j];
                }
            }
        }

        int city=-1;
        int cntMax=n+1;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(adjMat[i][j]<=distanceThreshold){
                    cnt++;
                }
            }

            if(cnt<=cntMax){
                city=i;
                cntMax=cnt;
            }
        }

        return city;

    }
};