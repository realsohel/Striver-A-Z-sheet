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
// Time => O(n+ m)
// SPace => O(N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA;
        ListNode *t2=headB;
    
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2)
                return t1;
            
            if(t1==NULL and t2==NULL)
                break;
            else if(t1==NULL)
                t1=headB;
            else if(t2==NULL)
                t2=headA;
            
        }
        
        return t1;
    }

// Better Approach
// Time => O(n+ m + max(n,m)) ~~ O(n+m)
// SPace => O(N)
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        int l1=0,l2=0;

        while(t1){
            l1++;
            t1=t1->next;
        }

        while(t2){
            l2++;
            t2=t2->next;
        }

        int diff=abs(l1-l2);
        t1=headA;
        t2=headB;

        if(l1<l2){
            while(diff--){
                t2=t2->next;
            }    
        }
        else if(l1>l2){
            while(diff--){
                t1=t1->next;
            } 
        }

        while(t1 and t2){
            if(t1==t2)
                return t1;
            t1=t1->next;
            t2=t2->next;
        }
        return NULL;
    }

    
// Brute Force
// Time => O(n+ m*n)
// SPace => O(N)
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;

        unordered_map<ListNode*, int>mp;

        while(t1){
            mp[t1]++;
            t1=t1->next;
        }

        while(t2){
            if(mp.find(t2)!=mp.end())
                return t2;
            
            t2=t2->next;
        }

        return NULL;
    }
};