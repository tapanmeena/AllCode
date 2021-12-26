#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* listCycle(ListNode* A) {
	if(A == NULL && A->next == NULL)
		return NULL;

	ListNode* slow = A;
	ListNode* fast = A->next->next;
	bool found = false;
	while(slow != NULL && fast != NULL)
	{
		if(slow == fast)
		{
			found = true;
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if(!found)
		return NULL;
	ListNode* curr = slow;
	while()
	return slow;
}


void printList(ListNode* A)
{
	int t = 6;
	ListNode* temp = A;
	while(temp != NULL)
	{
		if(t== 0)
			break;
		t--;
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = head->next->next;
	// head->next->next->next->next->next = new ListNode(6);
	// head->next->next->next->next->next->next = head->next->next;

	ListNode* t = listCycle(head);
	cout<<t->val<<endl;
	// printList(head);
}