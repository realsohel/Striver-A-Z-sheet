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

// Time Complexity = O(N)
// Space Complexity = O(1) 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        
        for(int i=1;i<=n;i++)
            fast=fast->next;
        
        ListNode* slow=head;

        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        if(fast==NULL){
            ListNode* node = head;
            head=head->next;
            delete node;
            return head;
        }

        ListNode* node = slow->next;
        slow->next=slow->next->next;
        delete node;

        return head;
    }

// Time Complexity = O(2N) ~~ O(N)
// Space Complexity = O(1) 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL or head->next==NULL)
            return NULL;
        
        ListNode*temp = head;
        ListNode*prev=NULL;
        n--;

        int size=0;

        while(temp){ // 
            size++;
            temp=temp->next;
        }

        int diff = size-n;
        temp=head;

        if(diff==1){
            prev=head;
            head=head->next;
            delete prev;
            return head;
        }

        while(temp){
            diff--;

            if(diff==0){
                ListNode* del = temp;
                prev->next=temp->next;
                delete temp;
                break;
            }

            prev=temp;
            temp=temp->next;
        }

        return head;
    }
};