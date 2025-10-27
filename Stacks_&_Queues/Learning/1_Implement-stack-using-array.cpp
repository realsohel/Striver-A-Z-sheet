#include <bits/stdc++.h>
using namespace std;


class myStack {
public:
    vector<int> arr;
    int size=0;
    myStack(int n) {
        // Define Data Structures
        size=n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return arr.size()==0;
    }

    bool isFull() {
        // check if the stack is full
        return size==arr.size();
    }

    void push(int x) {
        // inserts x at the top of the stack
        
        if(arr.size()==size)
            return;
            
        arr.push_back(x);
    }

    void pop() {
        // removes an element from the top of the stack
        if(arr.empty())
            return;
        
        arr.pop_back();   
    }

    int peek() {
        // Returns the top element of the stack
        if (arr.empty()) {
            return -1;
        }
        return arr.back();
    }
};  