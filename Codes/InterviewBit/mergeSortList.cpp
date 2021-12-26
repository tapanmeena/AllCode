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

ListNode* findMin(ListNode* temp)
{
	ListNode* min = temp;
	while(temp != NULL)
	{
		if(min->val > temp->val)
			min = temp;
		temp = temp->next;
	}
	return min;
}

ListNode* mergeSort(ListNode* A)
{
	ListNode* curr = A;
	
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
	head = mergeSort(head);
	printList(head);
}