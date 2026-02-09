#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Link - https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution {
public:
    void solve(Node* root, vector<int>& dfs, vector<vector<int>>& ans) {
        if (!root)
            return;
    
        dfs.push_back(root->data);
    
        if (!root->left && !root->right) {
            ans.push_back(dfs);
        }
    
        solve(root->left, dfs, ans);
        solve(root->right, dfs, ans);
    
        dfs.pop_back();
    }

    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int>dfs;
        if(!root)
            return ans;
                    
        solve(root,dfs,ans);
        
        return ans;
    }
};