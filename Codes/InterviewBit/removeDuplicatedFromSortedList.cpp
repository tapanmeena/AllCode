/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* duplicate(ListNode* A)
{
	if(A == NULL || A->next == NULL)
		return A;
	ListNode* curr = A;
	ListNode* next = A->next;
	while(curr->next != NULL)
	{
		if(curr->val == next->val)
		{
			curr->next = next->next;
			free(next);
			next = curr->next;
		}
		else
		{
			curr = curr->next;
			next = next->next;
		}
	}
	return A;
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
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(5);

	ListNode * t = duplicate(head);
	printList(t);
}