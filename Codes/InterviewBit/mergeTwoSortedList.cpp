#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* A, ListNode* B)
{
	if(A == NULL)
		return B;
	if(B == NULL)
		return A;
	ListNode* result = NULL;
	ListNode* finalList = NULL;
	while(A && B)
	{
		if(A->val <= B->val)
		{
			if(!result)
			{
				result = new ListNode(A->val);
				finalList = result;
			}
			else
			{
				result->next = new ListNode(A->val);
				result = result->next;
			}
			A = A->next;
		}
		else
		{
			if(!result)
			{
				result = new ListNode(B->val);
				finalList = result;
			}
			else
			{
				result->next = new ListNode(B->val);
				result = result->next;
			}
			B = B->next;
		}
	}

	if(A == NULL)
	{
		while(B)
		{
			result->next = new ListNode(B->val);
			result = result->next;
			B = B->next;
		}
	}
	else if(B == NULL)
	{
		while(A)
		{
			result->next = new ListNode(A->val);
			result = result->next;
			A = A->next;
		}
	}

	return finalList;
}

void printList(ListNode* A)
{
	ListNode* temp = A;
	while(temp != NULL)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(1);
	head1->next->next = new ListNode(2);
	head1->next->next->next = new ListNode(3);

	ListNode* head = new ListNode(2);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next->next->next = new ListNode(8);

	ListNode * t = merge(head,head1);
	printList(t);
}