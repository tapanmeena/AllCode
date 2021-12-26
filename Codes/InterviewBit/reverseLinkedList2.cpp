#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* reverseList(ListNode* A, int B, int C) {
    if(B == C)
        return A;
    bool first = false;
    if(B == 1)
        first = true;
	ListNode* next;
    ListNode* prev;
    ListNode* curr;
    ListNode* start;    
    ListNode* last;    
  
    curr = A;
    prev = NULL;

    for(int i = 1; i<B; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    start = prev;
    last = curr;

    prev = curr;
    curr = curr->next;
    while(curr != NULL && B != C){
        B++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(!first)
    {
        last->next = curr;
        start->next = prev;

        return A;
    }
    else
    {
        last->next = curr;
        A = prev;
        return A;
    }
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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);

    ListNode * t = reverseList(head, 1, 9);
    printList(t);
}