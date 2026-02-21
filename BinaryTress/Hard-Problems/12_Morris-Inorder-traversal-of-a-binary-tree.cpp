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

// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while(cur){
            if(!cur->left){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode *prev=cur->left;

                while(prev->right and prev->right!=cur){
                    prev=prev->right;
                }

                if(!prev->right){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }

        return inorder;
    }
};