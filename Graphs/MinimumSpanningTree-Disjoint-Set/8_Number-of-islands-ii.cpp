#include <bits/stdc++.h> 
using namespace std;

class DisjointSet{
public:
    vector<int> rank, parent,size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node==parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DisjointSet ds(m*n);

	vector<vector<int>> vis(n, vector<int>(m,0));
    vector<int> ans;
	int cnt=0;

	for(auto &it:q){
		int row = it[0];
		int col = it[1];

		if(vis[row][col]==1){
			ans.push_back(cnt);
			continue;
		}

		vis[row][col]=1;
		cnt++;
		
		int dr[]={-1, 0, 1, 0};
		int dc[]={0, 1, 0, -1};

		for(int i=0;i<4;i++){
			int newr = row + dr[i];
			int newc = col + dc[i];

			if(newr>=0 and newr<n and newc>=0 and newc<m){
				if(vis[newr][newc]==1){
					int currNode = row*m + col;
					int newNode = newr*m + newc;

					if(ds.findUParent(currNode) !=ds.findUParent(newNode)){
						cnt--;
						ds.unionBySize(currNode, newNode);
					}
				}
			}
		}

		ans.push_back(cnt);
	}

	return ans;

}