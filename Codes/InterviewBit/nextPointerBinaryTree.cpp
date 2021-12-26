#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeLinkNode* nextRight(TreeLinkNode* current)
{
    TreeLinkNode* currNext = current->next;
    
    while (currNext)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}

void connect(TreeNode* A)
{
	queue<TreeLinkNode *> Q;
    if(A)
        Q.push(A);
    A->next = NULL;
    
    while (!Q.empty())
    {
        TreeLinkNode* node = Q.front();
        if (node->left)
        {
            Q.push(node->left);
            if (node->right)
                node->left->next = node->right;
            else
                node->left->next = nextRight(node);
        }
        if (node->right)
        {
            Q.push(node->right);
            node->right->next = nextRight(node);
        }
        
        Q.pop();
    }
}

void printTree(TreeNode *root)
{
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		cout<<temp->val<<endl;
		if(temp->left == NULL || temp->right == NULL)
			continue;
		q.push(temp->left);
		q.push(temp->right);
	}
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	TreeNode *temp = root;
	printTree(temp);
	connect(temp);
}
