#include <bits/stdc++.h> 
using namespace std;

int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp ){

    if(j1<0 or j2<0 or j1>=c or j2>=c)
        return -1e8;
    
    if(i==r-1){
        
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int maxi = INT_MIN;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            int val=0;

            if(j1==j2){
                val= grid[i][j1];
            }
            else {
                val = grid[i][j1] + grid[i][j2];
            }

            val+= solve(i+1, j1+dj1, j2+dj2, r,c,grid, dp);
            maxi=max(maxi,val);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int tabulation(int n,int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else {
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                
                int maxi = INT_MIN;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int val=0;

                        if(j1==j2){
                            val= grid[i][j1];
                        }
                        else {
                            val = grid[i][j1] + grid[i][j2];
                        }

                        if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 and j2+dj2<m)
                            val+= dp[i+1][j1+dj1][j2+dj2];
                        else
                            val=INT_MIN;
                        maxi=max(maxi,val);
                    }
                }
                
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    // dp[r][c][c]
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));;
    // return solve(0,0, c-1, r,c,grid, dp);
    return tabulation(r,c,grid, dp);
}