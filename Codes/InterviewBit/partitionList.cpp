#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* temp)
{
	while(temp != NULL)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

ListNode* pushNode(ListNode* head, int data)
{
	if(head == NULL)
	{
		ListNode* temp = new ListNode(data);
		return temp;
	}
	ListNode* temp = head;
	while(temp->next != NULL)
		temp = temp->next;

	ListNode* temp1 = new ListNode(data);
	temp->next = temp1;
	return head;
}

ListNode* partition(ListNode* A, int value)
{
	ListNode *smaller = NULL, *greater = NULL;
	ListNode *pointer1, * pointer2;
	ListNode* result;
	while(A != NULL)
	{
		if(A->val < value)
		{
			if(smaller == NULL)
			{
				smaller = new ListNode(A->val);
				pointer1 = smaller;
			}
			else
			{
				smaller->next = new ListNode(A->val);
				smaller = smaller->next;
			}
		}
		else
		{
			if(greater == NULL)
			{
				greater = new ListNode(A->val);
				pointer2 = greater;
			}
			else
			{
				greater->next = new	ListNode(A->val);
				greater = greater->next;
			}
		}
		A = A->next;
	}
	if(smaller == NULL)
		return pointer2;

	if(greater == NULL)
		return pointer1;

	smaller->next = pointer2;

	return pointer1;
}

int main()
{
	ListNode* head;
	for(int i=1; i<=7; i++)
	{
		int val = rand()%10;
		head = pushNode(head, val);
	}

	printList(head);
	head = partition(head, 5);
	printList(head);
}