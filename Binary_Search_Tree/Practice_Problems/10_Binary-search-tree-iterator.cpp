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


// Link: https://leetcode.com/problems/binary-search-tree-iterator


class BSTIterator {
    stack<TreeNode*>stk;
public:
    vector<int>ptr;
    int idx=0;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = stk.top();
        stk.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
private:
    void pushAll(TreeNode* node){
        while(node){
            stk.push(node);
            node=node->left;
        }
    }
};
