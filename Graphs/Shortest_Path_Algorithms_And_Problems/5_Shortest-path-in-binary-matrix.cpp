#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Dijktra's Algorithm --> Accepted
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]!=0 or grid[n-1][n-1]!=0) return -1;
        
        // {dist, {i,j}}
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;
        q.push({1,{0,0}});

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(dis > dist[x][y]) continue;
            if(x==n-1 and y==n-1)return dist[x][y] ;

            for(int i=0;i<8;i++){
                int dr = x+drow[i]; 
                int dc = y+dcol[i]; 

                if(dr>=0 and dr<n and dc>=0 and dc<n and grid[dr][dc]==0){
                    if(dis+1<dist[dr][dc]){
                        dist[dr][dc] = dis + 1;   
                        q.push({dis+1,{dr,dc}});
                    }
                }
            }
        }

        return -1;

    }
// Using Plain BFS  --> Gives TLE
    int shortestPathBinaryMatrix1(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]!=0 or grid[n-1][n-1]!=0) return -1;
        
        // {dist, {i,j}}
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        int cnt=INT_MAX;

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            grid[x][y]=1;
            q.pop();
            cnt=min(cnt,dis);
            if(x==n-1 and y==n-1)return dis ;

            for(int i=0;i<8;i++){
                int dr = x+drow[i]; 
                int dc = y+dcol[i]; 

                if(dr>=0 and dr<n and dc>=0 and dc<n and grid[dr][dc]==0){
                    q.push({dis+1,{dr,dc}});
                }
            }
        }

        return -1;
    }
};