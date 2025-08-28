#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node *fast=head;
        Node *slow=head;

        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        
            if(slow==fast){

                Node *temp=slow->next;
                int cnt=1;
                while(temp->next!=slow){
                    cnt++;
                    temp=temp->next;
                }
                return cnt;
            }
        }

        return 0;
    }
};