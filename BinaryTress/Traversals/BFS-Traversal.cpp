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

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> level;

        for(int i=0;i<n;i++){
            Node* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;
}

// 1. Pre-Order Traversal in Iterative manner - 
vector<int> preorderTraversal(Node* root) {
    vector<int> res;
    if(!root) return res;

    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty()){
        Node* node = stk.top();
        stk.pop();

        res.push_back(node->data);
        
        if(node->right)stk.push(node->right);
        if(node->left)stk.push(node->left);
    }

    return res;
}


// 2. In-Order Traversal in Iterative manner - 
vector<int> inorderTraversal(Node* root) {
    vector<int> res;
    stack<Node*>stk;
    Node* node = root;
    while(true){
        if(node){
            stk.push(node);
            node = node->left;
        }
        else{
            if(stk.empty())break;

            node = stk.top();
            stk.pop();
            res.push_back(node->data);
            node=node->right;
        }
    }
    return res;

}

int main(){
    return 0;
}