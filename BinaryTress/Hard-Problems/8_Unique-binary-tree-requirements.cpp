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

// Link - https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

class Solution {
public:
    bool isPossible(int a, int b) {
        // code here
        if((a==1 and b==2) || (a==2 and b==1))
            return true;
        else if((a==1 and b==3) || (a==3 and b==1))
            return false;
        else if ((a==2 and b==3) || (a==3 and b==2))
            return true;
            
        return false;
    }
};
