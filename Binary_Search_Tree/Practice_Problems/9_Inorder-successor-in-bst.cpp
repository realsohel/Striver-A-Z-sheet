#include<bits/stdc++.h>
using namespace std;

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

// Link - https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1


class Solution {
    public:
    // APPROACH 2 - 
    // TIME => O(Height of the tree)
    // TIME => O(1)
    void solve(Node *root,Node *x,int&ans){
        if(!root) return;
        
        if(root->data>x->data){
            ans=root->data;
            solve(root->left,x,ans);
        }
        else if(root->data<=x->data)
            solve(root->right,x,ans);
    }
    
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        int ans=-1;
        solve(root,x,ans);
        return ans;
        
    }
    // APPROACH 1 - 
    // TIME => O(N+N)
    // TIME => O(2N)
    void solve(Node *root, vector<int>&ans){
        if(!root) return;
        
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        vector<int> ans;
        solve(root,ans);
        int res=-1;
        
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==x->data){
                res=ans[i+1];
                break;
            }
        }
        return res;
        
    }
};