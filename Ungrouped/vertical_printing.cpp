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

int min = 0, max = 0, current = 0;

void find_min_max(Node *root, int current){
	if(root == NULL)
		return;
	if(current < ::min)
		::min = current;
	else if(current > ::max)
		::max = current;

	find_min_max(root->left,current-1);
	find_min_max(root->right,current+1);
}

void print_vertical_tree(Node *root,int i,int current){
	// cout<<
	if(root == NULL)
		return;
	if(current == i){
		cout<<root->data<<" ";
	}
	// cout<<"<"<<root->data<<">";
	print_vertical_tree(root->left,i,current-1);
	print_vertical_tree(root->right,i,current+1);
}

void print_vertical(Node *root, int current){
	find_min_max(root,current);
	// cout<<"min"<<::min<<" "<<::max<<endl;
	for(int i=::min; i<=::max; i++){
		print_vertical_tree(root, i,0);
	}
}

void print_tree(Node *node){
	if(node == NULL)
		return;
	// if(node->left == NULL || node->right == NULL)
		// cout<<node->data<<" ";
	// if(node->right == NULL)
		// cout<<node->data<<" ";
	print_tree(node->left);
	print_tree(node->right);
	cout<<node->data<<" ";
}

int main(){
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->left = newNode(8);
	// print_tree(root);
	print_vertical(root,current);
	cout<<endl;
	return 0;
}