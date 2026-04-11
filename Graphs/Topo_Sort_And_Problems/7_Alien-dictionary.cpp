#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        int V = 26;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        vector<bool> present(V, false);

        // Mark present characters
        for(auto &word : words){
            for(char c : word){
                present[c - 'a'] = true;
            }
        }

        // Build graph
        for(int i = 0; i < words.size() - 1; i++){
            string s1 = words[i];
            string s2 = words[i + 1];

            int id1 = 0, id2 = 0;
            while(id1 < s1.size() && id2 < s2.size()){
                if(s1[id1] != s2[id2]){
                    int u = s1[id1] - 'a';
                    int v = s2[id2] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
                id1++;
                id2++;
            }

            if(id1 == s2.size() && s1.size() > s2.size()){
                return "";
            }
        }

        // Count unique characters
        int uniqueChars = 0;
        for(int i = 0; i < 26; i++){
            if(present[i]) uniqueChars++;
        }

        // Kahn's BFS
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(present[i] && indegree[i] == 0){
                q.push(i);
            }
        }

        string ans = "";
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node + 'a');

            for(auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.length() != uniqueChars) return "";

        return ans;
    }
};