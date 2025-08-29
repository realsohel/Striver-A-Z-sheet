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

// Optimal
// Time Complexity = O(N) ;
// Time Complexity = O(1);
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *evenHead=head->next;

        while(even and even->next){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }

        odd->next=evenHead;

        return head;
    }

// Brute Force
// Time Complexity = O(N) + O(N/2) --> O(3N/2);
// Time Complexity = O(N/2) --> O(N);
    ListNode* oddEvenList1(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> vec;
        ListNode* temp =head;
        ListNode* prev =NULL;
        int idx=1;
        
        while(temp){
            if(idx%2==0){
                vec.push_back(temp->val);
                prev->next=temp->next;
                ListNode* cur = temp;
                temp=temp->next;
                delete cur;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
            idx++;
        }

        for(int x:vec){
            prev->next = new ListNode(x);
            prev=prev->next;
        }
        return head;
    }
};