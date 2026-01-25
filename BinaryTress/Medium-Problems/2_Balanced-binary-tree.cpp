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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int lft = maxDepth(root->left);
        int rgt = maxDepth(root->right);

        if(lft==-1 or rgt==-1)
            return -1;
        
        if(abs(lft-rgt)>1)
            return -1;

        return 1 + max(rgt,lft);
    }
    bool isBalanced(TreeNode* root) {
        return maxDepth(root)!=-1;
    }
};