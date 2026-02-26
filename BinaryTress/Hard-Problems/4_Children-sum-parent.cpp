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

// Link - https://www.geeksforgeeks.org/problems/children-sum-parent/1


class Solution {
public:
    bool isSumProperty(Node *root) {
        if(!root)
            return true;

        // leaf node
        if(!root->left && !root->right)
            return true;

        int left = 0, right = 0;

        if(root->left)
            left = root->left->data;

        if(root->right)
            right = root->right->data;

        if(root->data == left + right && isSumProperty(root->left) && isSumProperty(root->right))
            return true;

        return false;
    }
};