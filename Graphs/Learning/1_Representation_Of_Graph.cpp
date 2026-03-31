#include<bits/stdc++.h>
using namespace std;


// 2. Using List -> Adj. List
int main(){

    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return 0;
}

// 1. Using Matrix -> Adj. Matrix
int main1(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b ;
        adj[a][b]=1;
        adj[b][a]=1;
    }


    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout << adj[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}