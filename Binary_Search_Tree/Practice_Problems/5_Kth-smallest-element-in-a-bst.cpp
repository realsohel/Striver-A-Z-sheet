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


// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/


class Solution {
public:

// Appraoch 1 - Morris Traversal
// TIME = O(N) 
// SPACE= O(1) 
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return 0;
        
        TreeNode* curr =root;
        int cnt=0;
        int ans=0;
        while(curr){
            if(!curr->left){
                cnt++;
                if(cnt==k)
                    ans= curr->val;
                
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;

                while(prev->right and prev->right!=curr){
                    prev=prev->right;
                }

                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k)
                        ans= curr->val;
                    
                    curr=curr->right;
                }
            }
        }

        return ans;
    }

// Appraoch 1 - DFS
// TIME = O(N) 
// SPACE= O(N) 
    void solve(TreeNode* root, int k,int &cnt,int&ans){
        if(!root)return ;
        solve(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        solve(root->right,k,cnt,ans);
        

    }
    int kthSmallest1(TreeNode* root, int k) {
        int cnt=0;
        int ans=0;
        solve(root,k,cnt,ans);
        return ans;
    }
};