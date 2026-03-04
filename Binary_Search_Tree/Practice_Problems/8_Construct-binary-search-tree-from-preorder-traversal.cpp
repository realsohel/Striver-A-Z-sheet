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

// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


class Solution {
public:
    TreeNode* solve(vector<int>&preorder, int &i, int bound){
        if(i==preorder.size() or preorder[i]>bound)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(preorder,i,root->val);
        root->right = solve(preorder,i,bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
};