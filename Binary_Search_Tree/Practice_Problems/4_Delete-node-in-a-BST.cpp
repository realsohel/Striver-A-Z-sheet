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


// Link: https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // Node found

            // Case 1: No left child
            if(!root->left) return root->right;

            // Case 2: No right child
            if(!root->right) return root->left;

            // Case 3: Both children exist

            TreeNode* leftSubtree = root->left;
            TreeNode* rightSubtree = root->right;

            // Find rightmost node in left subtree
            TreeNode* temp = leftSubtree;
            while(temp->right){
                temp = temp->right;
            }

            // Attach right subtree there
            temp->right = rightSubtree;

            return leftSubtree;
        }

        return root;
    }
};
