#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthElement(ListNode* A, int B)
{
	if(B <= 0)
		return A;
	int n = 0;
	ListNode* temp = A;
	while(temp != NULL)
	{
		n++;
		temp = temp->next;
	}
	if(n == 1 && B == 1)
		return NULL;
	temp = A;
	if(n < B)
	{
		A = A->next;
		free(temp);
		return A;
	}
	int remain = n - B;
	temp = A;
	for(int i=0; i<remain-1; i++)
		temp = temp->next;
	ListNode* temp1 = temp;
	temp1 = temp1->next;
	temp->next = temp->next->next;
	free(temp1);
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
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(5);

	ListNode * t = removeNthElement(head, 0);
	printList(t);
}