#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void pushNode(Node* root, int value)
{
	if(root == NULL)
	{
		root = new Node(value);
		return;
	}
	while(root->next != NULL)
	{
		root = root->next;
	}
	Node* tempNode = new Node(value);
	root->next = tempNode;
}

void printList(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<" -> ";
		head = head->next;
		int x;
		cin>>x;
	}
}

void detectCycle(Node* head)
{
	int length = 0;
	Node* culprit = NULL;
	bool first = false;
	unordered_map<Node*, int> umap;
	while(head != NULL)
	{
		// cout<<"as";
		if(umap.find(head) == umap.end())
		{
			umap[head] = 1;
		}
		else
		{
			if(culprit == head)
			{
				cout<<"Culprit : "<<head->data<<" with length "<<length<<endl;
				return;
			}
			if(!first)
			{
				culprit = head;
				cout<<"Culprit : "<<head->data<<endl;
				first = true;
			}
			length++;
			// return;
		}
		head = head->next;
	}
}

int main()
{
	Node* root = new Node(1);
	pushNode(root, 2);
	pushNode(root, 3);
	pushNode(root, 4);
	pushNode(root, 5);
	pushNode(root, 6);
	pushNode(root, 8);
	Node* cycle = new Node(7);
	root->next->next->next->next->next->next->next = cycle;
	cycle->next = root->next->next->next;
	// printList(root);
	detectCycle(root);
	// cout<<root->data<<endl;
}