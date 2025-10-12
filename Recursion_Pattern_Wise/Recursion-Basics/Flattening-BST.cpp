#include<bits/stdc++.h> 
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
public:
    Node *flattenBST(Node *root) {
        // code here
        
        if(root==NULL)
            return NULL;
        
        Node *head = flattenBST(root->left);
        
        root->left=NULL;
        root->right = flattenBST(root->right);
        
        if(head){   
            Node *temp=head;
            
            while(temp and temp->right){
                temp=temp->right;
            }
            temp->right=root;
        }
        else
            head=root;
        
        
        return head;
                
    }
};

