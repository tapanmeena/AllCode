#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
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
		ListNode* temp = new ListNode();
		temp->val = data;
		temp->next = NULL;
		return temp;
	}
	ListNode* temp = head;
	while(temp->next != NULL)
		temp = temp->next;

	ListNode* temp1 = new ListNode();
	temp1->val = data;
	temp1->next = NULL;
	temp->next = temp1;
	return head;
}

ListNode* reorder(ListNode* A)
{
	ListNode* curr = A;
	if(curr == NULL || curr->next == NULL || curr->next->next == NULL)
		return A;
	while(curr->next->next != NULL)
	{
		// cout<<"curr value "<<curr->val<<endl;
		ListNode* prevLast = curr;
		ListNode* last = curr->next;
		if(last == NULL)
			return A;
		while(last->next != NULL)
		{
			prevLast = last;
			last = last->next;
		}

		if(prevLast == curr)
			return A;

		ListNode* temp = curr->next;
		curr->next = last;
		curr->next->next = temp;
		curr = curr->next->next;
		prevLast->next = NULL;
		// cout<<"curr value "<<curr->val<<endl;
		// printList(A);
		if(curr->next == NULL)
			return A;
	}
	return A;
}

int main()
{
	ListNode* head;
	for(int i=1; i<=7; i++)
		head = pushNode(head, i);

	printList(head);
	head = reorder(head);
	printList(head);
}