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

// 1. Delete Head
Node *deleteHead(Node*head){

    if(head==nullptr or head->next==nullptr)
        return nullptr;

    Node *temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete temp;

    return head;
}

// 2. Delete Tail
Node *deleteTail(Node *head){
    if(head==nullptr or head->next==nullptr)
        return nullptr;
    
    Node *temp=head;

    while(temp->next){
        temp=temp->next;
    }
    Node *previous = temp->prev;
    previous->next=nullptr;
    temp->prev=nullptr;
    delete temp;

    return head;
}


// 3. Delete Kth Node
Node *deleteKthNode(Node *head,int k){
    int cnt=0;
    Node *temp=head;

    while(temp){
        cnt++;
        if(cnt==k)
            break;
        temp=temp->next;
    }

    Node *back = temp->prev;
    Node *front = temp->next;

    if(back==nullptr and front==nullptr){
        delete temp;
        return nullptr;
    }
    else if(back==nullptr){
        return deleteHead(head);
    }
    else if(front==nullptr){
        return deleteTail(head);
    }

    back->next=front;
    front->prev=back;
    temp->next=nullptr;
    temp->prev=nullptr;

    delete temp;

    return head;
}


// 4. Delete the Value

Node *deleteValue(Node *head,int val){
    if(head==NULL)
        return NULL;

    Node *temp=head;

    while(temp){
        if(temp->data==val)
            break;
        temp=temp->next;
    }

    Node *back = temp->prev;
    Node *front = temp->next;

    if(back==nullptr and front==nullptr){
        delete temp;
        return nullptr;
    }
    else if(back==nullptr){
        return deleteHead(head);
    }
    else if(front==nullptr){
        return deleteTail(head);
    }

    back->next=front;
    front->prev=back;
    temp->next=nullptr;
    temp->prev=nullptr;

    delete temp;

    return head;
}


int main(){

    vector<int> arr = {1,2,3,52,90,4,5};

    Node *head = convertArr2LL(arr);
    TraverseLL(head);

    // head=deleteHead(head);
    // TraverseLL(head);

    // head=deleteTail(head);
    // TraverseLL(head);
    // head=deleteKthNode(head,4);
    // TraverseLL(head);

    head=deleteValue(head,3);
    TraverseLL(head);
    return 0;
}