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

// Link - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root)
            return ans;

        map<int,map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            pair<Node*, pair<int,int>> temp = q.front();
            q.pop();

            Node* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(node->data);

            if(node->left)
                q.push({node->left, {hd-1,lvl+1}});
            if(node->right)
                q.push({node->right, {hd+1,lvl+1}});
        }

        for(auto &col : nodes) {
            for(auto &lvl : col.second) {
                ans.push_back(lvl.second[0]);
                break;
            }
        }

        return ans;
    }
};