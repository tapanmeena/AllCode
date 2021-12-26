#include <bits/stdc++.h>
using namespace std;

#define inputArray(arr,n) for(int ia = 0; ia<n; ia++) cin>>arr[ia]
#define printArray(arr,n) for(int ia = 0; ia<n; ia++) cout<<arr[ia]<<" "
#define lli long long int

struct Node 
{ 
    int data; 
    struct Node *left, *right;
}; 
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

int main(){
	Node *root = newNode(1);
	return 0;
}