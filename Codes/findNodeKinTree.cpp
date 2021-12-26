#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void findClosestKey(Node* root, int key, int &diff, int &val)
{
	if(root == NULL)
	{
		// cout<<"Nothing found"<<endl;
		// cout<<key<<endl;
		return;
	}
	if(root->data == key)
	{
		val = root->data;
		// cout<<"Answer <<<<>>>>>>"<<key<<endl;
		return;
	}
	if(abs(root->data - key) < diff)
	{
		diff = abs(root->data - key);
		val = root->data;
		// cout<<"Answer <<<<>>>>>>"<<val<<endl;
		// return;
	}
	if(root->data < key)
		findClosestKey(root->right, key, diff, val);
	if(root->data > key)
		findClosestKey(root->left, key, diff, val);
}

int main()
{
	Node* root = new Node(9);
	root->left = new Node(4);
	root->right = new Node(17);
	root->left->left = new Node(3);
	root->left->right = new Node(6);
	root->left->right->left = new Node(5);
	root->left->right->right = new Node(8);
	root->right->right = new Node(22);
	root->right->right->left = new Node(20);

	inorder(root);
	cout<<endl;
	int key = 4;
	int diff = INT_MAX, val = 0;
	findClosestKey(root, key, diff, val);
	cout<<"Answer "<<val<<endl;
	key = 18;
	diff = INT_MAX, val = 0;
	findClosestKey(root, key, diff, val);
	cout<<"Answer "<<val<<endl;
	key = 12;
	diff = INT_MAX, val = 0;
	findClosestKey(root, key, diff, val);
	cout<<"Answer "<<val<<endl;
	key = 8;
	diff = INT_MAX, val = 0;
	findClosestKey(root, key, diff, val);
	cout<<"Answer "<<val<<endl;

	return 0;
}