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
    // DFS
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }

    // BFS
    int maxDepthBFS(TreeNode* root) {
        if(!root)
            return 0;
        int cnt=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            cnt++;
        }

        return cnt;
    }
};