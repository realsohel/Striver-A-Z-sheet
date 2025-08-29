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

//  Optimal
//  Time => O(N/2 + N/2 + N/2 + N/2) ~~ O(2N) ~~ O(N)
//  Space => O(1)
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* newHead=NULL;

        while(fast!=NULL and (fast->next!=NULL and fast->next->next!=NULL)){
            slow=slow->next;
            fast=fast->next->next;
        }

        newHead=reverseList(slow->next);

        ListNode* first=head;
        ListNode* second=newHead;
        
        while(second){
            if(first->val!=second->val){
                reverseList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(newHead);
        return true;
    }

// Brute Force
// Time = O(2N) ~~ O(N)
// Space = O(N)
    bool isPalindrome1(ListNode* head) {
        vector<int> vec;
        ListNode *temp  = head;

        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int i=0,l=vec.size()-1;

        while(i<=l){
            if(vec[i]!=vec[l])
                return false;
            i++;
            l--;
        }

        return true;
    }
};