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


// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

class Solution {
public:

    struct Node{
        int sum;
        int mini;
        int maxi;
        bool isBST;
    };

    int ans = 0;

    Node solve(TreeNode* root){
        
        if(root == NULL){
            return {0, INT_MAX, INT_MIN, true};
        }

        Node left = solve(root->left);
        Node right = solve(root->right);

        Node curr;

        if(left.isBST && right.isBST && 
           root->val > left.maxi && root->val < right.mini){

            curr.sum = left.sum + right.sum + root->val;
            curr.mini = min(root->val, left.mini);
            curr.maxi = max(root->val, right.maxi);
            curr.isBST = true;

            ans = max(ans, curr.sum);
        }
        else{
            curr.isBST = false;
            curr.sum = 0;
            curr.mini = INT_MIN;
            curr.maxi = INT_MAX;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};