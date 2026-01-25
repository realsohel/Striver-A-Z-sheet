#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

// DFS

// 1. Inorder Traversal
void inOrder(Node* root, vector<int> &res){
    if(root==NULL)
        return;
    
    inOrder(root->left,res);
    res.push_back(root->data);
    inOrder(root->right,res);
}
vector<int> inorderTraversal(Node* root) {
    vector<int> res;
    inOrder(root,res);
    return res;
}

// 2. Pre-Order Traversal
void PreOrder(Node *root,vector<int>&res){
    if(root==NULL)
        return;
    
    res.push_back(root->data);
    PreOrder(root->left,res);
    PreOrder(root->right,res);
}

vector<int> preorderTraversal(Node* root) {
    vector<int> res;
    PreOrder(root,res);
    return res;
}


// 2. Post-Order Traversal
void PostOrder(Node *root,vector<int>&res){
    if(root==NULL)
        return;
    
    PostOrder(root->left,res);
    PostOrder(root->right,res);
    res.push_back(root->data);
}

vector<int> postorderTraversal(Node* root) {
    vector<int> res;
    PostOrder(root,res);
    return res;
}



int main(){

    return 0;
}