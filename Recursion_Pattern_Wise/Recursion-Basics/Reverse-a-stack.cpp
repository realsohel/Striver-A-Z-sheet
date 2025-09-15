#include<bits/stdc++.h> 
using namespace std;

// APproach 2
// Time = O(N^2)
// Space = O(N) ==> O(1)  No extra space used.
void insertAtBottom(stack<int> &stk, int el){
        
    if(stk.empty()){
        stk.push(el);
        return;
    }
    
    int t = stk.top();
    stk.pop();
    
    insertAtBottom(stk,el);
    stk.push(t);
}

void reverse(stack<int> &stk) {
    // code here
    if(stk.size()<=1)
        return;

    int t = stk.top();
    stk.pop();
    
    reverse(stk);
    insertAtBottom(stk,t);
}

// APproach 1
// Time = O(N^2)
// Space = O(N) + O(N) ==> call stack space + temp stack space
void reverse(stack<int> &stk) {
    // code here
    
    if(stk.size()<=1)
        return;
    
    int t = stk.top();
    stk.pop();
    
    reverse(stk); // Trust
    
    stack<int> temp;
    
    while(!stk.empty()){
        temp.push(stk.top());
        stk.pop();
    }
    
    temp.push(t);
    
    while(!temp.empty()){
        stk.push(temp.top());
        temp.pop();
    }
}