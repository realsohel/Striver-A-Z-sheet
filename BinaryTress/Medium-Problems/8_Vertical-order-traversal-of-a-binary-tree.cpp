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
// Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;

        map<int,map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(node->val);

            if(node->left)
                q.push({node->left, {hd-1,lvl+1}});
            if(node->right)
                q.push({node->right, {hd+1,lvl+1}});
        }

        for(auto &col : nodes) {
            vector<int> column;
            for(auto &lvl : col.second) {
                sort(lvl.second.begin(), lvl.second.end());
                for(int val : lvl.second)
                    column.push_back(val);
            }
            ans.push_back(column);
        }

        return ans;
    }
};