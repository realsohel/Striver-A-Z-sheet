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
    
// OPTIMAL APPRAOCH
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root==p or root==q)
            return root;
        
        TreeNode* leftN = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN = lowestCommonAncestor(root->right,p,q);

        if(leftN and rightN)
            return root;

        if(leftN and !rightN)
            return leftN;

        if(!leftN and rightN)
            return rightN;
        
        return NULL;
    }


    // BRUTE FORCE APPROACH
    // bool lca(TreeNode* root, TreeNode* node, vector<TreeNode*>&data){
    //     if(!root)
    //         return false;
        
    //     data.push_back(root);
    //     if(root== node){
    //         return true;
    //     }

    //     if(lca(root->left,node,data) || lca(root->right,node,data))
    //         return true;
        
    //     data.pop_back();

    //     return false;
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     vector<TreeNode*> p1;
    //     vector<TreeNode*> q1;

    //     lca(root,p,p1);
    //     lca(root,q,q1);

    //     int i=0,j=0;
    //     TreeNode* ans=NULL;
    //     while(i<p1.size() and j<q1.size() and p1[i]==q1[i]){
    //         ans  = p1[i];
    //         i++;
    //         j++;
    //     }

    //     return ans;
    // }
};