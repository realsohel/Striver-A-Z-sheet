#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int res;
    void backTrack(vector<vector<int>>& grid, int x,int y, int &nonObsCnt, int &cnt ){
        
        // Base Case 
        if((x<0 or y<0) or (x>=grid.size() or y>=grid[0].size()) or grid[x][y]==-1)
            return;
            
        if(grid[x][y]==2){
            if(cnt==nonObsCnt)
                res++;
            return;
        }


        // Do 
        int temp=grid[x][y];
        grid[x][y] =  -1;
        cnt++;

        // Explore
        backTrack(grid,x+1,y,nonObsCnt,cnt);
        backTrack(grid,x-1,y,nonObsCnt,cnt);
        backTrack(grid,x,y+1,nonObsCnt,cnt);
        backTrack(grid,x,y-1,nonObsCnt,cnt);

        // Undo
        grid[x][y]=temp;
        cnt--;

    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int nonObsCnt=1;
        int x=-1,y=-1;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    nonObsCnt++;
                else if(grid[i][j]==1){
                    x=i,y=j;
                }
            }
        }

        res=0;
        int cnt=0;
        backTrack(grid,x,y,nonObsCnt,cnt);

        return res;

    }
};