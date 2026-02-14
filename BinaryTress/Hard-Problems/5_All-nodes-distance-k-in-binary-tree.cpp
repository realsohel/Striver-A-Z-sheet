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

// Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/



class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;

    void inOrder(TreeNode* root){
        if(!root)
            return;
        
        if(root->left)
            parent[root->left]=root;

        inOrder(root->left);
        if(root->right)
            parent[root->right]=root;
        inOrder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>&res){
        queue<TreeNode*> q;
        unordered_set<int> isVisited;

        q.push(target);
        isVisited.insert(target->val);

        while(!q.empty()){
            int n= q.size();

            if(k==0)
                break;
            
            while(n--){
                TreeNode* node = q.front();
                q.pop();

                // Left
                if(node->left and !isVisited.count(node->left->val)){
                    q.push(node->left);
                    isVisited.insert(node->left->val);
                }

                // Right
                if(node->right and !isVisited.count(node->right->val)){
                    q.push(node->right);
                    isVisited.insert(node->right->val);
                }

                // Parent
                if(parent.count(node) and !isVisited.count(parent[node]->val)){
                    q.push(parent[node]);
                    isVisited.insert(parent[node]->val);
                }
            }
            k--;
        }

        while(!q.empty()){
            // cout << q.front()->val << " ";
            res.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        inOrder(root);
        BFS(target,k,res);
        return res;
    }
};