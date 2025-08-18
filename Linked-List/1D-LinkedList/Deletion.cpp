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

// 1. Delete Head
Node *deleteHead(Node*head){
    if(head==nullptr){
        return nullptr;
    }
    Node *temp = head;
    head=head->next;

    free(temp); // or delete temp;

    return head;
}

// 2. Delete Tail
Node *deleteTail(Node *head){
    if(head==nullptr or head->next==nullptr){
        return nullptr;
    }

    Node *temp = head;

    while(temp->next->next){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;
}


// 3. Delete Kth Elemeent
Node *deleteKthElement(Node *head, int k){
    if(head==nullptr or k<=0)
        return head;
    
    if(k==1)
        return deleteHead(head);
    
    Node *temp = head;
    Node *prev = nullptr;
    int cnt=0;

    while(temp){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}

// Delete the Value
Node *deleteValue(Node *head,int val){

    if(head==nullptr)
        return head;
    
    if(val==head->data)
        return deleteHead(head);
    
    Node *temp = head;
    Node *prev = nullptr;

    while(temp){
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }

        prev=temp;
        temp=temp->next;
    }

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

    // TraverseLL(head);
    // head=deleteHead(head);
    // TraverseLL(head);
    // head=deleteTail(head);
    // TraverseLL(head);
    
    // TraverseLL(head);
    // head=deleteKthElement(head,8);
    // TraverseLL(head);

    TraverseLL(head);
    head=deleteValue(head,10);
    TraverseLL(head);
}