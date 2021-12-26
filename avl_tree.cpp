#include <bits/stdc++.h>
using namespace std;

#define inputArray(arr,n) for(int ia = 0; ia<n; ia++) cin>>arr[ia]
#define printArray(arr,n) for(int ia = 0; ia<n; ia++) cout<<arr[ia]<<" "
#define lli long long int

struct Node
{ 
    int key; 
    node *left; 
    node *right; 
    int height; 
    int count; 
}; 

Node* newNode(int key) 
{ 
    Node* node = new Node();
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    node->count = 1; 
    return node;
} 

int max(int a, int b){
	return (a>b)?a : b ;
}

int height(Node* root){
	if(root==NULL)
		return 0;
	return root->height;
}

Node* insert(Node* root,int key){
	if(root==NULL)
		return newNode(key);
	
	
}

void preOrder(Node *root){
	if(root==NULL)
		return;
	cout<<root->key<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	node* root = NULL;
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 7);
	root = insert(root, 17);
	preOrder(root);
	return 0;
}




// int max(int a, int b); 
  
// // A utility function to get height of the tree 
// int height(struct node *N) 
// { 
//     if (N == NULL) 
//         return 0; 
//     return N->height; 
// } 
  
// // A utility function to get maximum of two integers 
// int max(int a, int b) 
// { 
//     return (a > b)? a : b; 
// } 

// struct node *rightRotate(struct node *y) 
// { 
//     struct node *x = y->left; 
//     struct node *T2 = x->right; 
  
//     // Perform rotation 
//     x->right = y; 
//     y->left = T2; 
  
//     // Update heights 
//     y->height = max(height(y->left), height(y->right))+1; 
//     x->height = max(height(x->left), height(x->right))+1; 
  
//     // Return new root 
//     return x; 
// } 
  
// // A utility function to left rotate subtree rooted with x 
// // See the diagram given above. 
// struct node *leftRotate(struct node *x) 
// { 
//     struct node *y = x->right; 
//     struct node *T2 = y->left; 
  
//     // Perform rotation 
//     y->left = x; 
//     x->right = T2; 
  
//     //  Update heights 
//     x->height = max(height(x->left), height(x->right))+1; 
//     y->height = max(height(y->left), height(y->right))+1; 
  
//     // Return new root 
//     return y; 
// } 
  
// // Get Balance factor of node N 
// int getBalance(struct node *N) 
// { 
//     if (N == NULL) 
//         return 0; 
//     return height(N->left) - height(N->right); 
// } 
  
// struct node* insert(struct node* node, int key) 
// { 
//      1.  Perform the normal BST rotation 
//     if (node == NULL) 
//         return (newNode(key)); 
  
//     // If key already exists in BST, icnrement count and return 
//     if (key == node->key) 
//     { 
//         (node->count)++; 
//         return node; 
//     } 
  
//      /* Otherwise, recur down the tree */
//     if (key < node->key) 
//         node->left  = insert(node->left, key); 
//     else
//         node->right = insert(node->right, key); 
  
//     /* 2. Update height of this ancestor node */
//     node->height = max(height(node->left), height(node->right)) + 1; 
  
//     /* 3. Get the balance factor of this ancestor node to check whether 
//        this node became unbalanced */
//     int balance = getBalance(node); 
  
//     // If this node becomes unbalanced, then there are 4 cases 
  
//     // Left Left Case 
//     if (balance > 1 && key < node->left->key) 
//         return rightRotate(node); 
  
//     // Right Right Case 
//     if (balance < -1 && key > node->right->key) 
//         return leftRotate(node); 
  
//     // Left Right Case 
//     if (balance > 1 && key > node->left->key) 
//     { 
//         node->left =  leftRotate(node->left); 
//         return rightRotate(node); 
//     } 
  
//     // Right Left Case 
//     if (balance < -1 && key < node->right->key) 
//     { 
//         node->right = rightRotate(node->right); 
//         return leftRotate(node); 
//     } 
  
//     /* return the (unchanged) node pointer */
//     return node; 
// } 
