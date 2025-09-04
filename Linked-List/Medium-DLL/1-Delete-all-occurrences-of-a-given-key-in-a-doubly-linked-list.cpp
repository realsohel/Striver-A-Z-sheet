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

    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* curr = *head_ref;
    
        while (curr != nullptr) {
            if (curr->data == x) {
                Node* temp = curr;
    
                if (curr->prev != nullptr) {
                    curr->prev->next = curr->next;
                } else {
                    *head_ref = curr->next;
                }
    
                if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                }
    
                curr = curr->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }
};