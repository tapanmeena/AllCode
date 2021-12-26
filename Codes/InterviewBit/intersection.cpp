#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* listCycle(ListNode* A, ListNode* B) {
	map<ListNode*, int> umap;
	while(A != NULL)
	{
		umap[A]++;
		A = A->next;
	}
	while(B != NULL)
	{
		if(umap[B]>0)
		{
			return B;
		}
		B = B->next;
	}
	return NULL;
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
	head->next->next->next->next->next = new ListNode(6);
	// head->next->next->next->next->next = new ListNode(6);
	// head->next->next->next->next->next->next = head->next->next;

	ListNode* head1 = new ListNode(11);
	head1->next = new ListNode(22);
	head1->next->next = new ListNode(33);
	head1->next->next->next = head->next->next->next;
	// head->next->next->next->next->next = new ListNode(6);
	// head->next->next->next->next->next->next = head->next->next;
	printList(head1);
	cout<<endl;	
	ListNode* t = listCycle(head, head1);
	cout<<t->val<<endl;
	// printList(head);
}