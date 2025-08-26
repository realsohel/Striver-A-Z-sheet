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

Node *insertionAtHead(Node *head, int val){
    if(head==NULL)
        return new Node(val);
    
    Node *node = new Node(val);
    node->next=head;
    node->prev=NULL;
    head->prev=node;
    head=node;

    return head;
}

Node *insertAtTail(Node *head, int val){
    if(head==NULL)
        return new Node(val);

    Node *temp=head;

    while(temp->next)
        temp=temp->next;
    
    Node *node = new Node(val);
    temp->next=node;
    node->prev=temp;
    node->next=NULL;

    return head;
}

Node *insertAtKthPos(Node *head, int k,int val){
    if(head==NULL and k==1)
        return new Node(val);
    
    int cnt=0;
    Node *temp=head;

    while(temp){
        cnt++;

        if(cnt==k)
            break;
        
        temp=temp->next;
    }
    
    Node *node = new Node(val);
    Node *back=temp->prev;
    Node *front=temp->next;

    if(back==NULL)
        return insertionAtHead(head,val);
    else if(front==NULL)
        return insertAtTail(head,val);
    
    node->next=front;
    front->prev=node;

    node->prev=back;
    back->next=node;

    return head;
}

int main(){

    vector<int> arr = {1,2,3,52,90,4,5};

    Node *head = convertArr2LL(arr);
    TraverseLL(head);

    // head=insertionAtHead(head,90);
    // TraverseLL(head);

    // head=insertAtTail(head,40);
    // TraverseLL(head);


    head=insertAtKthPos(head,3,15);
    TraverseLL(head);


    return 0;
}