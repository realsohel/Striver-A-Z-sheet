#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    void solve(vector<int>& cookies, int idx, int k, vector<int> &children, int &res){
        //  Basse case
        if(idx>=cookies.size()){
            int maxi = *max_element(children.begin(), children.end());
            res = min(res, maxi);
            return;
        }

        int cookie = cookies[idx];

        for(int i=0;i<k;i++){
            // Do
            children[i] +=cookie;

            if(children[i]==0)
                break;
                
            // Explore
            solve(cookies,idx+1,k,children,res);
            
            // Undo
            children[i] -=cookie;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k,0);
        int res = INT_MAX;

        solve(cookies,0,k,children,res);

        return res;    
    }
};