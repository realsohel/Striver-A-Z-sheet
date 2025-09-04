#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
}; 


class Solution {
public:

// Time = O(N)
// Space = O(1)
    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node *temp=head;
        
        while(temp and temp->next){
            Node *nextNode =temp->next;
            
            while(nextNode and nextNode->data==temp->data){
                Node *dup = nextNode;
                nextNode=nextNode->next;
                delete dup;
            }
            
            temp->next=nextNode;
            if(nextNode)
                nextNode->prev=temp;
            
            temp=temp->next;
        }
        
        
        return head;
    }

};