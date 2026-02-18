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

// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


class Solution {
public:
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int start, int end, int &idx) {
        
        if (start > end)
            return NULL;

        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int i = start;
        while (i <= end && inorder[i] != val)
            i++;

        root->right = solve(postorder, inorder, i + 1, end, idx);
        root->left  = solve(postorder, inorder, start, i - 1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n - 1;

        return solve(postorder, inorder, 0, n - 1, idx);
    }

};