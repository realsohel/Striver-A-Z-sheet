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

    ListNode* reverseList(ListNode* head) {
        ListNode* temp =head;

        ListNode* prev=NULL;
        ListNode* front=NULL;

        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* head, int k){
        if(head==NULL or k==1)
            return head;
        
        ListNode* t=head;
        int cnt=0;

        while(t){
            cnt++;
            if(cnt==k)
                return t;
            
            t=t->next;
        }
        
        return NULL;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode *temp =head;
        ListNode *nextNode=NULL;
        ListNode *prev=NULL;

        
        while(temp){
            ListNode* kthNode = findKthNode(temp,k);

            if(kthNode==NULL){
                prev->next=temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next=NULL;

            ListNode* rev = reverseList(temp);

            if(temp==head){
                head=kthNode;
            }
            else{
                prev->next=kthNode;
            }

            prev=temp;
            temp=nextNode;
        }

        return head;
    }
};