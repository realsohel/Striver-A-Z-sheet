#include <bits/stdc++.h>
using namespace std;

class Heap{
    
public:
    vector<int> arr;
    int size;
    Heap(){
        arr.push_back(-1);
        size = 0;
    }

    void insert(int val){
        size++;
        arr.push_back(val);
        int idx=size;

        while(idx>1){
            int prnt = idx/2;

            if(arr[prnt]>arr[idx]){
                swap(arr[prnt],arr[idx]);
                idx=prnt;
            }
            else
                return;
        }

    }

    void deletion(){
        if(size==0)
            return;
        
        arr[1]=arr[size];
        size--;
        arr.pop_back();

        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;
            
            if(left<size and arr[left]<arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if(right<size and arr[right]<arr[i]){
                swap(arr[right],arr[i]);
                i=right;
            }
            else
                return;
        }
    }

    void print(){
        for(int x=1;x<arr.size();x++){
            cout << arr[x] << " ";
        }
        cout << endl;
    }
};


void heapify(vector<int>&arr, int n , int i){
    int small = i;
    int left=2*i;
    int right=2*i+1;

    if(left<n and arr[small]>arr[left]){
        small=left;
    }
    if(right<n and arr[small]>arr[right])
        small=right;
    
    if(small!=i){
        swap(arr[i],arr[small]);
        heapify(arr,n,small);
    }
}

bool isMinHeap(int arr[], int n) {
    // Your code goes here
    
    for(int i=0;i<n;i++){
        int val = arr[i];
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n and val<arr[left])
            return false;
        else if(right<n and val<arr[right])
            return false;
    }
    
    return true;
}

int main(){
    Heap h;
    h.insert(10);
    h.insert(5);
    h.insert(12);
    h.insert(11);
    h.insert(4);
    h.insert(110);

    h.print();
    
    h.deletion();
    h.print();

    vector<int> arr = {-1,9,3,1,6,4};
    for(int i=arr.size()/2; i>0;i--){
        heapify(arr,arr.size(),i);
    }

    cout << "Pritning: \n";
    for(int i=1;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}