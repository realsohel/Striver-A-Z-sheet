#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
public:

// Optimal
// Time = O(2N) ~~ O(N)
// SPace = O(1)
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node *left=head;
        Node *temp=head;
        Node *right=NULL;
        
        vector<pair<int, int>> ans;
        
        while(temp){
            right=temp;
            temp=temp->next;
        }
        
        while(left->data < right->data){
            int sum = left->data + right->data;
            
            if(sum==target){
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum<target){
                left=left->next;
            }
            else{
                right=right->prev;
            }
        }
        
        return ans;
    }

// Brute Force
// Time = O(N*N)
// SPace = O(1)
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node *t1=head;
        vector<pair<int, int>> ans;
        
        while(t1){
            Node *t2=t1->next;
            
            while(t2){
                if(t1->data+t2->data == target){
                    ans.push_back({t1->data,t2->data});
                }
                else if(t1->data+t2->data > target)
                    break;
                t2=t2->next;
            }
            
            t1=t1->next;
        }
        
        return ans;
    }
};
