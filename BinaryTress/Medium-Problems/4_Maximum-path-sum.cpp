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
    int solve(TreeNode * root, int &res){
        if(!root)
            return 0;
        
        int lft = solve(root->left,res);
        int rgt = solve(root->right,res);
        
        int case1 = lft + rgt + root->val;
        int case2 = max(lft,rgt) + root->val;
        int case3 = root->val;
        
        res = max({res,case1,case2,case3});
        
        return max(case3, case2);
    }
    int findMaxSum(TreeNode *root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};