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
    bool isIdentical(TreeNode* r1, TreeNode* r2) {
        if(r1==NULL && r2==NULL)
            return true;
        else if(r1==NULL or r2==NULL)
            return false;
        
        bool same = r1->val==r2->val;
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        
        
        if((same and left )and right)
            return true;
        else
            return false;
    }
};