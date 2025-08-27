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

// Approach - 2
// Time = O(N)
// Space = O(1)
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL)
            return head;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

// Approach - 1
// Time = O(2N) ~~O(N)
// Space = O(1)
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* temp2=head;
        int n=0;
        
        while(temp){
            n++;
            temp=temp->next;
        }

        ListNode *s=NULL;
        int cnt=0;
        
        while(temp2){
            cnt++;
            if(cnt==n/2){
                s=temp2->next;
                break;
            }
            temp2=temp2->next;
        }
        
        return s;
    }
};

