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

// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        flatten(root->left);
        flatten(root->right);

        TreeNode* rightSide = root->right;

        root->right=root->left;
        root->left=NULL;

        TreeNode* temp=root;
        while(temp->right){
            temp=temp->right;
        }

        temp->right=rightSide;
    }
};