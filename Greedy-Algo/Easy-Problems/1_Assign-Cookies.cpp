// Link - https://leetcode.com/problems/assign-cookies/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// OPTIMAL 
// TIME => O(NLOGN + MLOGM)
// SPACE => O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count=0;
        int i=0,j=0;

        while(i<n and j<m){
            if(s[j]>=g[i]){
                s[j]=-1;
                count++;
                i++;
                j++;
            }
            else
                j++;
        }

        return count;
    }

// BRUTE FORCE  --> TLE
// TIME => O(NLOGN + MLOGM + N*M)
// SPACE => O(1)
    int findContentChildren1(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[j]>=g[i]){
                    count++;
                    s[j]=-1;
                    break;
                }
            }
        }

        return count;
    }
};