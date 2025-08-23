#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x, Node *y){
        data=x;
        next=y;
    }
    Node(int x){
        data=x;
        next=nullptr;
    }

};


// 1. Insert at Head
Node *insertAtHead(Node *head, int val){
    if(head==nullptr)
        return new Node(val);
    
    Node *newNode = new Node(val);
    newNode->next=head;
    return newNode;
}

// 2. Insert at Tail
Node *insertAtTail(Node *head, int val){
    if(head==nullptr)
        return new Node(val);

    Node *temp = head;
    Node *newNode = new Node(val);

    while(temp){
        if(temp->next==nullptr){
            temp->next=newNode;
            newNode->next=nullptr;
            break;
        }

        temp=temp->next;
    }

    return head;
}

// 3. Insert at Kth Position
Node *insertAtKthPosition(Node *head, int val, int k){
    if(k<=0)
        return head;

    if(k==1)
        return insertAtHead(head, val);

    Node *temp = head;
    Node *newNode = new Node(val);
    int count = 1;

    while(temp && count < k - 1){
        temp = temp->next;
        count++;
    }

    if(temp == nullptr) // If k is greater than the length of the list
        return head;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}   

Node *convertArr2LL(vector<int> &arr){
    Node *head= new Node(arr[0]);
    Node *mover = head;

    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;

}

void TraverseLL(Node *head){
    Node *temp=head;

    while(temp){
        cout << temp->data << " -> ";
        temp=temp->next;
    }

    cout << "null\n"; 
}

int main(){

    vector<int> arr = {1,2,3,90,4,5};

    Node *head = convertArr2LL(arr);

    TraverseLL(head);
    head=insertAtHead(head,100);
    TraverseLL(head);
    head=insertAtTail(head,500);
    TraverseLL(head);
}