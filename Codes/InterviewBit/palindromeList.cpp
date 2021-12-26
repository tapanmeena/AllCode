#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

int lPalin(ListNode* A)
{
	stack<int> s;
	int length = 0;
	ListNode* temp = A;
	while(temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	if(length == 1)
		return 1;
	temp = A;
	bool found = false;
	for(int i=0;i<length/2;i++)
	{
		s.push(A->val);
		A = A->next;
	}
	if(length%2 != 0)
		A = A->next;
	for(int i = 0; i<length/2; i++)
	{
		int value = s.top();
		s.pop();
		if(value == A->val)
		{
			A = A->next;
			found = true;
		}
		else
		{
			found = false;
			break;
		}
	}
	if(!found)
		return 0;
	else
		return 1;
}

int main()
{
	ListNode* A = new ListNode(1);
	// A->next = new ListNode(2);
	// A->next->next = new ListNode(3);
	// A->next->next->next = new ListNode(1);
	// A->next->next->next->next = new ListNode(3);
	// A->next->next->next->next->next = new ListNode(2);
	// A->next->next->next->next->next->next = new ListNode(1);
	cout<<lPalin(A)<<endl;
}