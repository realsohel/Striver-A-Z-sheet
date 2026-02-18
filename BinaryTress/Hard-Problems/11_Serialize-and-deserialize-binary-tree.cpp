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

// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";

        queue<TreeNode*> q;
        q.push(root);
        string ans="";

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node) ans.append("$,");
            else {
                ans.append(to_string(node->val)+',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << ans <<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');

            if(str=="$"){
                node->left=NULL;
            }
            else{
                TreeNode* leftN = new TreeNode(stoi(str));
                node->left=leftN;
                q.push(leftN);
            }
            getline(s,str,',');

            if(str=="$"){
                node->right=NULL;
            }
            else{
                TreeNode* rightN = new TreeNode(stoi(str));
                node->right=rightN;
                q.push(rightN);
            }
        }

        return root;
    }
};