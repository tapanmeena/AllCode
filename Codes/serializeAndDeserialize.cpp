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

int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
        return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void serialize(Node *root, vector<int> &A)
{
    if(root == NULL)
    {
        A.push_back(-1);
        return;
    }
    cout<<root->data<<" ";
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

int currlength = 0;
void deserialize(vector<int> &A, Node* &root2,int length)
{
	if(currlength == length)
		return;
	if(A[currlength] == -1)
		return;
	cout<<A[currlength]<<" ";
	root2 = new Node(A[currlength]);

	currlength++;
	deserialize(A, root2->left, A.size());

	currlength++;
	deserialize(A, root2->right, A.size());
}

int main()
{
    vector<int> result;
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    cout<<endl;
    serialize(root, result);
    cout<<endl;
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    Node* root2 = NULL;
    deserialize(result, root2, result.size());
    cout<<endl;
    inorder(root2);
    return 0;
}