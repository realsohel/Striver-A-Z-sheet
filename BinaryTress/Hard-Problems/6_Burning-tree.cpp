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

// Link - https://www.geeksforgeeks.org/problems/burning-tree/1


class Solution {
public:
    unordered_map<Node*,Node*>parent;
    
    Node* findParentAndTarget(Node *root,int target){
        if(!root) return 0;
        
        queue<Node*>q;
        q.push(root);
        Node* ans=NULL;
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node *node = q.front();
                q.pop();
                
                if(node->data==target)
                    ans=node;
                
                if(node->left){
                    parent[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        
        return ans;
        
    }
    
    
    int BFS(Node* root, int cnt){
        if(!root)return 0;
    
        queue<Node*> q;
        unordered_set<int> isVisited;

        q.push(root);
        isVisited.insert(root->data);

        while(!q.empty()){
            int n= q.size();
            
            while(n--){
                Node* node = q.front();
                q.pop();

                // Left
                if(node->left and !isVisited.count(node->left->data)){
                    q.push(node->left);
                    isVisited.insert(node->left->data);
                }

                // Right
                if(node->right and !isVisited.count(node->right->data)){
                    q.push(node->right);
                    isVisited.insert(node->right->data);
                }

                // Parent
                if(parent.count(node) and !isVisited.count(parent[node]->data)){
                    q.push(parent[node]);
                    isVisited.insert(parent[node]->data);
                }
            }
            cnt++;
        }
        return cnt;
    }
    
    int minTime(Node* root, int target) {
        
        Node* targetNode = findParentAndTarget(root, target);
        
        return BFS(targetNode, 0) - 1; 
    }

};