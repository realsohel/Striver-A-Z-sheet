#include<bits/stdc++.h>
using namespace std;


// RIGHT SIDE VIEW 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Link - https://leetcode.com/problems/binary-tree-right-side-view/


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> lvl;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                lvl.push_back(node->val);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            int rgsz = lvl.size();
            ans.push_back(lvl[rgsz-1]);
        }

        return ans;
    }
};

// LEFT SIDE VIEW 

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Link - https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

class Solution {
    public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root)
            return ans;
        
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> lvl;

            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();

                lvl.push_back(node->data);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(lvl[0]);
        }

        return ans;
        
    }
};