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
// Link - https://leetcode.com/problems/symmetric-tree/


class Solution {
public:
    // DFS
    bool chk(TreeNode* l, TreeNode* r){
        if(!l and !r)return true;
        if(!l or !r)return false;

        if((r->val==l->val) && (chk(l->right,r->left) && chk(l->left,r->right)))
            return true;
        
        return false;
    }

    bool isSymmetric1(TreeNode* root) {
        if(!root) return true;
        return chk(root->left,root->right);
    }

    // // BFS
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* lft = q.front();q.pop();
            TreeNode* rgt = q.front();q.pop();

            if(!lft && !rgt) continue;
            if(!lft || !rgt) return false;

            if(lft->val!=rgt->val) return false;

            q.push(lft->left);
            q.push(rgt->right);
            
            q.push(lft->right);
            q.push(rgt->left);
        }

        return true;
    }
};