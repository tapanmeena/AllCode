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
        
    ListNode* tempHead = new ListNode(-1);
    tempHead->next = A;
    ListNode* prev = tempHead;
    while (A != NULL)
    {
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (prev->next == A)
            prev = prev->next; 
        else 
            prev->next = A->next;
            
        A = A->next;
    }
    return tempHead->next;


	// if(A == NULL || A->next == NULL)
	// 	return A;
	// ListNode* prev = A;
	// ListNode* curr = A;
	// ListNode* next = A->next;
	// bool dupFound = false;
	// while(curr->next != NULL)
	// {
	// 	if(curr->val == next->val)
	// 	{
	// 		curr->next = next->next;
	// 		free(next);
	// 		next = curr->next;
	// 		dupFound = true;
	// 	}
	// 	else
	// 	{
	// 		if(dupFound)
	// 		{
	// 			ListNode* temp = curr;
	// 			curr = curr->next;
	// 			next = next->next;
	// 			prev->next = curr;
	// 			free(temp);
	// 		}
	// 		else
	// 		{
	// 			prev = curr;
	// 			curr = curr->next;
	// 			next = next->next;
	// 		}
	// 		dupFound = false;
	// 	}
	// }
	// if(dupFound)
	// {
	// 	cout<<"sa";
	// 	if(prev == NULL)
	// 		cout<<"s";
	// 	prev->next = NULL;
	// 	free(curr);
	// }
	// return A;
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

	ListNode * t = duplicate(head1);
	printList(t);
}