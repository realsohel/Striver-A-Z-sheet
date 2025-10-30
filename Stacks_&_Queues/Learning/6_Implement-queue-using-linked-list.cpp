#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

public:
    Node *head;
    Node *tail;
    int sz;
    myQueue() {
        // Initialize your data members
        head=NULL;
        tail=NULL;
        sz=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return sz==0 or head==NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node *newNode = new Node(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            sz++;
            return;
        }
        tail->next=newNode;
        tail=newNode;
        
        sz++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        if (head == NULL) // if queue became empty
            tail = NULL;
        delete temp;
        sz--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(head==NULL)
            return -1;
            
        return head->data;
    }

    int size() {
        // Returns the current size of the queue.
        return sz;
    }
};
