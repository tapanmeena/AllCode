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

ListNode* sortList(ListNode* A)
{
	ListNode* curr = A;
	int n = 0;
	while(curr != NULL)
	{
		n++;
		curr = curr->next;
	}
	curr = A;
	for(int i = 0; i<n; i++)
	{
		bool swap = false;
		while(curr->next != NULL)
		{
			if(curr->val > curr->next->val)
			{
				int temp = curr->val;
				curr->val = curr->next->val;
				curr->next->val = temp;
				swap = true;
			}
			curr = curr->next;
		}
		if(!swap)
			break;
		curr = A;
	}
	return A;
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
	head = sortList(head);
	printList(head);
}