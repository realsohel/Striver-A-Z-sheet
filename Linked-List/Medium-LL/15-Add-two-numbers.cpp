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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode *res= new ListNode(-1);
        ListNode *ans= res;
        int carry=0;

        while(t1 and t2){
            int data = t1->val+t2->val + carry;

            if(data<10){
                carry=0;
                ListNode * node=new ListNode(data);
                ans->next=node;
                ans=ans->next;
            }
            else{
                carry = 1;
                ListNode * node=new ListNode(data-10);
                ans->next=node;
                ans=ans->next;
            }

            t1=t1->next;
            t2=t2->next;
        }

        while(t1){
            int data = t1->val + carry;
            if(data<10){
                carry=0;
                ListNode * node=new ListNode(data);
                ans->next=node;
                ans=ans->next;
            }
            else{
                carry = 1;
                ListNode * node=new ListNode(data-10);
                ans->next=node;
                ans=ans->next;
            }

            t1=t1->next;
        }
        while(t2){
            int data = t2->val + carry;
            if(data<10){
                carry=0;
                ListNode * node=new ListNode(data);
                ans->next=node;
                ans=ans->next;
            }
            else{
                carry = 1;
                ListNode * node=new ListNode(data-10);
                ans->next=node;
                ans=ans->next;
            }

            t2=t2->next;
        }

        if(carry>0){
            ListNode * node=new ListNode(1);
            ans->next=node;
            ans=ans->next;
        }
        return res->next;
    }
};