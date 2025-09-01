#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

// Time => O(N)
// Space => O(1) 
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return NULL;
            
        ListNode* fast=head;
        ListNode *slow=head;
        ListNode * prev=NULL;

        while(fast and fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }

        ListNode *node = slow;
        prev->next=slow->next;
        delete node;
        
        return head;
    }

// Time => O(N) ~~ O(2N)
// Space => O(1) 
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return NULL;

        int n=0;
        ListNode* temp=head;

        while(temp){
            n++;
            temp=temp->next;
        }

        int todel = (n/2)+1;
        temp=head;
        ListNode* prev=NULL;

        while(temp){
            todel--;

            if(todel==0)
                break;
            prev=temp;
            temp=temp->next;
        }

        ListNode* node = temp;
        prev->next=temp->next;
        delete node;

        return head;
    }
};
