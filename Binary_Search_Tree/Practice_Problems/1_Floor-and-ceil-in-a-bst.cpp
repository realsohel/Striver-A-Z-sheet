#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
    public:

    int findCeil(Node* root, int x) {
        // code here
        int cil=-1;
        while(root){
            
            if(root->data==x){
                cil=root->data;
                return cil;
            }
            else if(root->data>x){
                cil=root->data;
                root=root->left;
            }
            else
                root=root->right;
        }
        
        return cil;
    }

    int findFloor(Node* root, int x) {
        // code here
        int flr=-1;
        while(root){
            
            if(root->data==x){
                flr=root->data;
                return flr;
            }
            else if(root->data<x){
                flr=root->data;
                root=root->right;
            }
            else
                root=root->left;
        }
        
        return flr;
    }
};