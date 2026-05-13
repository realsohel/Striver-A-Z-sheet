#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n==1 and m==1)return 0;

        // {abs-diff,{row,col}}
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;

        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int absD = it.first;
            int x= it.second.first;
            int y = it.second.second;

            if(absD>dist[x][y])continue;

            if(x==n-1 and y==m-1) return dist[x][y];

            for(int i=0;i<4;i++){
                int dr = x + drow[i];
                int dc = y + dcol[i];

                if(dr>=0 and dr<n and dc>=0 and dc<m ){
                    int ed = abs(heights[x][y]-heights[dr][dc]);
                    int eff = max(ed,absD);

                    if(eff<dist[dr][dc]){
                        dist[dr][dc]=eff;
                        pq.push({eff, {dr,dc}});
                    }
                }
            }
        }

        return 0;
    }
};