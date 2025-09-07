#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:

    // Brute Force
    // Time = O(N)
    // Space = O(N)
    Node* copyRandomList(Node* head) {
        
        Node*temp=head;
        unordered_map<Node*, Node*>mp;

        while(temp){
            Node *newN = new Node(temp->val);
            mp[temp] = newN;

            temp=temp->next;
        }

        temp=head;

        while(temp){
            Node *copy = mp[temp];
            copy->next=mp[temp->next];
            copy->random=mp[temp->random];

            temp=temp->next;
        }

        return mp[head];
    }
};