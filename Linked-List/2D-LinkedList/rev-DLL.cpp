#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;


    Node(int x, Node *y,Node *z){
        data=x;
        next=y;
        prev=z;
    }
    Node(int x){
        data=x;
        next=nullptr;
        prev=nullptr;
    }
};


Node *convertArr2LL(vector<int> &arr){

    Node *head = new Node(arr[0]);
    Node *temp=head;

    for(int i=1;i<arr.size();i++){
        Node *newNode = new Node(arr[i],nullptr,temp);
        temp->next=newNode;
        temp=newNode;
    }

    return head;
}

void TraverseLL(Node *head){
    Node *temp=head;

    while(temp){
        cout << temp->data << " <=> ";
        temp=temp->next;
    }

    cout << "null\n"; 
}


// OPTIMAL Solution
// Time = O(N)
// Space = O(1)
Node *reverseDLL2(Node *head){
    Node *temp=head;
    Node *node=NULL;
    
    while(temp){
        node = temp->prev;
        temp->prev=temp->next;
        temp->next=node;

        temp=temp->prev;
    }


    return node->prev;
}

// Brute Force
// Time = O(2N) ~~ O(N)
// Space = O(N)
Node *reverseDLL(Node *head){
    Node *temp=head;
    stack<int> stk;

    while(temp){
        stk.push(temp->data);
        temp=temp->next;
    }

    temp=head;

    while(temp){
        temp->data=stk.top();
        stk.pop();
        temp=temp->next;
    }

    return head;
}

int main(){

    vector<int> arr = {1,2,3,52,90,4,5};

    Node *head = convertArr2LL(arr);
    TraverseLL(head);

    head= reverseDLL(head);
    TraverseLL(head);
    
    head= reverseDLL2(head);
    TraverseLL(head);

}