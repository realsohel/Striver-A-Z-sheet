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


// Link: https://leetcode.com/problems/validate-binary-search-tree/


class Solution {
public:
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(!root)return true;

        if(root->val<=mini || root->val>=maxi)
            return false;
        
        bool left = solve(root->left,mini,root->val);
        bool right = solve(root->right,root->val,maxi);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};