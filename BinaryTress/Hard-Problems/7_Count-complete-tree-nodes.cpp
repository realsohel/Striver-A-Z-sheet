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

// Link - https://leetcode.com/problems/count-complete-tree-nodes/description/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int cnt=1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    cnt++;
                }
                if(node->right){
                    q.push(node->right);
                    cnt++;
                }
            }

        }

        return cnt;
    }
};