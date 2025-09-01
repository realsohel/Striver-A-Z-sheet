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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* t=dummy;

        while(left and right){
            if(left->val < right->val){
                t->next=left;
                t=left;
                left=left->next;
            }
            else{
                t->next=right;
                t=right;
                right=right->next;

            }
        }
        
        if(left)
            t->next=left;
        else
            t->next=right;

        return dummy->next;
    }
    ListNode *findMiddle(ListNode *head){
        ListNode* s=head;
        ListNode* f=head->next;

        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }

        return s;
    }

    ListNode *solve(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;

        ListNode *middle = findMiddle(head);
        ListNode *left=head;
        ListNode *right = middle->next;
        middle->next=NULL;

        left= solve(left);
        right= solve(right);

        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return solve(head);
    }


// Time Complexit => O(N*LogN) ~~ O(2N + NLOGN)
// Space Complexity => O(N)
    ListNode* sortList1(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        vector<int> a;
        ListNode *temp=head;

        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }

        temp=head;
        sort(a.begin(),a.end());
        int i=0;
        while(temp){
            temp->val=a[i];
            i++;
            temp=temp->next;
        }

        return head;
    }
};