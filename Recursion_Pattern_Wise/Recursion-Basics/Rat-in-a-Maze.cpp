#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& maze, int i,int j, string path, vector<string> &res){
        
        if( ( (i<0 or i>=n) or (j<0 or j>=n) ) or maze[i][j]==0)
            return;
        
        if(i==n-1 and j==n-1){
            res.push_back(path);
            return;
        }
        
        maze[i][j]=0;
        
        // Down
        path.push_back('D');
        dfs(maze,i+1,j,path,res);
        path.pop_back();
        
        // Right
        path.push_back('R');
        dfs(maze,i,j+1,path,res);
        path.pop_back();
        
        // Up
        path.push_back('U');
        dfs(maze,i-1,j,path,res);
        path.pop_back();
        
        // Left
        path.push_back('L');
        dfs(maze,i,j-1,path,res);
        path.pop_back();
        
        maze[i][j]=1;
        
    }
    
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> res;
        n=maze.size();
        dfs(maze,0,0,"",res);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};