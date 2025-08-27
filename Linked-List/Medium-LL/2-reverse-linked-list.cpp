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

// Recurrsion
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* newHead= reverseList(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;

        return newHead;
    }


    // Iteration
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
};





// ================================================= EXPLANATION =================================================

// Answer: This problem asks us to **reverse a singly linked list**.  
// The head of the original list becomes the tail, and the last node becomes the new head.  
// We must return the new head pointer after reversal.

// Task:
// - You are given the head of a singly linked list.
// - Rearrange the list so that the order of nodes is reversed.
// - Return the new head of the reversed linked list.

// Key Observations:
// - Each node has only one pointer (`next`), so we cannot directly traverse backward.
// - To reverse links, we need to carefully adjust `next` pointers while traversing the list once.
// - We need three pointers to manage this safely:
//     → `temp` → current node being processed
//     → `prev` → the node that should come before current node after reversal
//     → `front` → stores the next node temporarily so we don’t lose access to the rest of the list

// Approach (Iterative):
// 1. Initialize pointers:
//    - `prev = NULL` (since new tail will point to NULL)
//    - `temp = head` (start from the head)
// 2. Loop until `temp` is NULL:
//    - Save `front = temp->next` (store next node).
//    - Reverse the link: `temp->next = prev`.
//    - Move `prev` forward: `prev = temp`.
//    - Move `temp` forward: `temp = front`.
// 3. When loop ends, `prev` will point to the new head.
// 4. Return `prev`.

// Why this works:
// - Each step carefully breaks one link and reattaches it in the opposite direction.
// - By storing the next node (`front`), we never lose track of the remaining list.
// - At the end, all links are reversed and `prev` becomes the new head.

// Example Walkthrough:
// Input list: head → [1] → [2] → [3] → NULL
// Step 1: temp = [1], front = [2], reverse: [1] → NULL, prev = [1], temp = [2]
// Step 2: temp = [2], front = [3], reverse: [2] → [1], prev = [2], temp = [3]
// Step 3: temp = [3], front = NULL, reverse: [3] → [2], prev = [3], temp = NULL
// End: prev = [3] (new head)
// Final list: head → [3] → [2] → [1] → NULL

// Time Complexity: O(n) — each node visited once.
// Space Complexity: O(1) — only constant extra pointers used.

