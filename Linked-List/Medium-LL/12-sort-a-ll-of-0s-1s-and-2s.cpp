#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:

//  Time => O(N)
// Space => O(1)
    Node* segregate(Node* head) {
        if(head==NULL or head->next==NULL)
            return head;

        Node* zeroH= new Node(-1);
        Node* zeroP=zeroH;
        Node* oneH= new Node(-1);
        Node* oneP=oneH;
        Node* twoH= new Node(-1);
        Node* twoP=twoH;

        Node *temp=head;
        
        while(temp){
            if(temp->data==0){
                zeroP->next=temp;
                zeroP=temp;
            }
            else if(temp->data==1){
                oneP->next=temp;
                oneP=temp;
            }
            else{
                twoP->next=temp;
                twoP=temp;
            }
            temp=temp->next;
        }

        zeroP->next = (oneH->next) ? oneH->next : twoH->next; 
        
        if(oneH->next){
            oneP->next=twoH->next;
        }
        twoP->next=NULL;
        return zeroH->next;
    }



//  Time => O(2N)
// Space => O(1)
    Node* segregate2(Node* head) {
        if(head==NULL or head->next==NULL)
            return head;

        Node *t = head;
        int cnt0=0,cnt1=0,cnt2=0;

        while(t){
            if(t->data==0)
                cnt0++;
            else if(t->data==1)
                cnt1++;
            else
                cnt2++;
            t=t->next;
        }

        t=head;
        
        while(t and cnt0>0){
            t->data=0;
            cnt0--;
        }
        while(t and cnt1>0){
            t->data=1;
            cnt1--;
        }
        while(t and cnt2>0){
            t->data=2;
            cnt2--;
        }

        return head;
    }

//  Time => O(2N+NLOGN)
// Space => O(N)
    Node* segregate1(Node* head) {
        // code here
        vector<int> vec;
        Node *temp = head;

        while(temp){
            vec.push_back(temp->data);
            temp=temp->next;
        }

        sort(vec.begin(),vec.end());

        temp=head;
        int i=0;
        while(temp){
            temp->data=vec[i];
            i++;
            temp=temp->next;
        }

        return head;
    }

};