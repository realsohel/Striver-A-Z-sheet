#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
public:

// Optimal
// Time => O(N)
// Space => O(1) 
    
    int func(Node *temp){
        
        if(temp==NULL)
            return 1;
        
        int carry = func(temp->next);
        temp->data+=carry;

        if(temp->data<10){
            return 0;
        }

        temp->data=0;
        return 1;
    }
    Node* addOne(Node* head) {
        Node *temp=head;
        int carry = func(temp);

        if(carry > 0){
            Node *node = new Node(1);
            node->next=head;
            return node;
        }

        return head;
    }

    Node* reverseList(Node* head) {
        Node* temp =head;

        Node* prev=NULL;
        Node* front=NULL;

        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
    }

// Better
// Time => O(3N) ~~O(N)
// Space => O(1) 
    Node* addOne1(Node* head) {
        head=reverseList(head);
        Node *temp=head;
        int carry=1;

        while(temp){
            temp->data+=carry;

            if(temp->data<10){
                carry=0;
                break;
            }
            else{
                carry=1;
                temp->data=0;
            }

            temp=temp->next;
        }

        if(carry>0){
            Node *node = new Node(1);
            temp->data=0;
            temp->next=node;
        }

        head=reverseList(head);
        return head;
    }
// Brute Force
// Time => O(3N) ~~O(N)
// Space => O(N) 
    Node* addOne1(Node* head) {
        // Your Code here
        Node *temp = head;
        vector<int>a;
        
        while(temp){
            a.push_back(temp->data);
            temp=temp->next;
        }
        
        int n = a.size();
        a[n-1] +=1;
        
        for(int i=n-1;i>0;i--){
            if(a[i]>9){
                a[i-1]+=1;
                a[i]=0;
            }
        }
        Node *newHead=new Node(1);
        bool flg=false;
        
        if(a[0]>9){
            a[0]=0;
            flg=true;
        }
        
        temp=head;
        int i=0;
        
        while(temp){
            temp->data=a[i];
            i++;
            temp=temp->next;
        }
        
        if(flg){
            newHead->next=head;
            return newHead;
        }

        return head;
        
    } 
};