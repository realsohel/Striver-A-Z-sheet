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
    int length=0;

    while(temp){
        cout << temp->data << " -> ";
        temp=temp->next;
        length++;
    }

    cout << "null\n"; 
    cout << "Length - " << length << endl;
}

bool searchInLL(Node *head,int targ){
    Node *temp=head;

    while(temp){
        if(temp->data==targ)
            return true;
        temp=temp->next;
    }

    return false;
}

int main(){

    vector<int> arr = {1,2,3,90,4,5};

    Node *head = convertArr2LL(arr);

    TraverseLL(head);

    if(searchInLL(head,2)){
        cout << "Present\n";
    }
    else
        cout << "Not-Present\n";
}