#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(a[i], b[i]);
    }

    while (q--) {
        char c;
        int x;
        ll v;
        cin >> c >> x >> v;
        x--;

        sum -= min(a[x], b[x]);

        if (c == 'A') {
            a[x] = v;
        } else {
            b[x] = v;
        }

        sum += min(a[x], b[x]);

        cout << sum << "\n";
    }

    return 0;
}




// class Node{
// public:
//     int data;
//     Node* next;
//     Node* prev;


//     Node(int x, Node *y,Node *z){
//         data=x;
//         next=y;
//         prev=z;
//     }
//     Node(int x){
//         data=x;
//         next=nullptr;
//         prev=nullptr;
//     }
// };


// Node *convertArr2LL(vector<int> &arr){

//     Node *head = new Node(arr[0]);
//     Node *temp=head;

//     for(int i=1;i<arr.size();i++){
//         Node *newNode = new Node(arr[i],nullptr,temp);
//         temp->next=newNode;
//         temp=newNode;
//     }

//     return head;
// }

// void TraverseLL(Node *head){
//     Node *temp=head;

//     while(temp){
//         cout << temp->data << " <=> ";
//         temp=temp->next;
//     }

//     cout << "null\n"; 
// }



// int main(){

//     vector<int> arr = {1,2,3,52,90,4,5};

//     Node *head = convertArr2LL(arr);
//     TraverseLL(head);
//     return 0;
// }