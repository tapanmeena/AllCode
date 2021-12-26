#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// bool checkLeftSubTree(TreeNode *root, int val)
// {
// 	if(root == NULL)
// 		return true;
// 	if(root->val <= val && checkLeftSubTree(root->left, root->val) && checkRightSubTree(root->right, root->val))
// 		return true;
// 	return false;
// }

// bool checkRightSubTree(TreeNode *root, int val)
// {
// 	if(root == NULL)
// 		return true;
// 	if(root->val > val && checkLeftSubTree(root->left, root->val) && checkRightSubTree(root->right, root->val))
// 		return true;
// 	return false;
// }

// int Solution::isValidBST(TreeNode *A)
// {
// 	if(checkLeftSubTree(A->left, A-> val) && checkRightSubTree(A->right, A-> val) && isValidBST(A->left) && isValidBST(A->right))
// 		return 1;
// 	return 0;
// }
/*
		   10
		  /  \
		 5    12
		/ \	  / \
	   4   6 11  13
*/
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

bool isLesser(TreeNode *root, int value)
{
	if(root == NULL)
		return true;
	if(root->val <= value
		&& isLesser(root->left, value)
		&& isLesser(root->right, value))
		return true;
	return false;
}

bool isGreater(TreeNode *root, int value)
{
	if(root == NULL)
		return true;
	if(root->val > value 
		&& isGreater(root->left, value)
		&& isGreater(root->right, value))
		return true;
	return false;
}

int isValidBST(TreeNode *root)
{
	if(root == NULL)
		return 1;
	if(isLesser(root->left, root->val)
		&& isGreater(root->right, root->val)
		&& isValidBST(root->left)
		&& isValidBST(root->right))
		return 1;
	return 0;
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
	// TreeNode *root = new TreeNode(10);
	// root->left = new TreeNode(8);
	// root->right = new TreeNode(12);
	// root->left->left = new TreeNode(4);
	// root->left->right = new TreeNode(9);
	// root->right->left = new TreeNode(11);
	// root->right->right = new TreeNode(13);
	TreeNode *root = new TreeNode(11);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(3);

	TreeNode *temp = root;
	printTree(temp);
	cout<<isValidBST(temp);
}
/*
11 3 2 4 1 3 -1 -1 -1 -1 -1 -1


         1
        / \ 
       2    3
          /
        4
         \
          5

*/