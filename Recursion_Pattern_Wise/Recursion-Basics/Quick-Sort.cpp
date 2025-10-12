#include<bits/stdc++.h> 
using namespace std;

int partition(vector<int>&arr, int low, int high){

    int pivot = arr[high];
    int pi = high;
    
    for(int i=low;i<=high;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[pi]);
            pi=i;
        }
    }

    swap(arr[pi],arr[high]);

    return pi;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low>=high)
        return;

    int pivot = partition(arr,low,high);
    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot+1,high);

}