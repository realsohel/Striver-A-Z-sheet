#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree
    

class Solution {
public:
    void solve(TreeNode* root, TreeNode* node){
        if(!root)
            return;
        
        if(root->val>node->val)
            solve(root->left,node);
        if(root->val<node->val)
            solve(root->right,node);
        
        if(!root->left && root->val>node->val){
            root->left=node;
        }
        if(!root->right && root->val<node->val){
            root->right=node;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root)
            return node;
        solve(root,node);
        return root;
    }
};