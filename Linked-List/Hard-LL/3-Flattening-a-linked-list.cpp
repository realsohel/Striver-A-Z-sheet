#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
public:
    Node *flatten(Node *head) {
        // code here
        Node *temp=head;
        vector<int> vec;
        
        while(temp){
            Node *btn = temp;
            
            while(btn){
                vec.push_back(btn->data);
                btn=btn->bottom;
            }
            temp=temp->next;
        }
        
        sort(vec.begin(),vec.end());
        Node* dummy = new Node(0);
        Node* curr = dummy;
        for (int val : vec) {
            curr->bottom = new Node(val);
            curr = curr->bottom;
        }
        
        return dummy->bottom;
    }
};