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


// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            if(reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);

        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if(!root) return false;

        BSTIterator l(root, false); // inorder
        BSTIterator r(root, true);  // reverse inorder

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k)
                return true;
            else if(i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};

class Solution1 {
public:
// Brute Force
// TIME => O(N)
// SPACE => O(N)
    unordered_set<int>st;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        if(!st.empty() && st.count(k-root->val))
            return true;
        st.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};