#include <iostream>
//##include "InsertNodeAtBetween_linkedlist."
using namespace std;

struct Node{
	int data;
	Node *next;
};

void printList(Node *n){
	while(n!=NULL){
		cout<<n->data<<endl;
		n=n->next;
	}
}

void pushEnd(Node *n,int value){
	Node *temp=new Node;
	temp->data=value;
	temp->next=NULL;
	if(n==NULL){
		n=temp;
	}
	else{
		while(n->next!=NULL){
			n=n->next;
		}
		n->next=temp;
	}
}
void pushBetween(Node *n,int key,int value){
	Node *as=new Node;
	as->data=value;
	for(int i=1;i<key;i++){
		n=n->next;
	}
	as->next=n->next;
	n->next=as;
}
Node* deleteDuplicate(Node* head){
	Node *tmp=head;
	Node *prev=NULL;
	Node *next=NULL;
	int n;
	if(tmp==NULL)
		return head;
	n=tmp->data;
	while(tmp && tmp->next){
		if(tmp->data==tmp->next->data){
			Node *temp=tmp->next->next;
			free(tmp->next);
			tmp->next=temp;
		}
		else{
			tmp=tmp->next;
		}
	}
	return head;
}

int main(){
	Node *list=new Node;
	list->data=0;
	list->next=NULL;
	int i=1;
	while(i!=5){
		pushEnd(list,i);
		i++;
	}
	pushBetween(list,2,2);
	pushBetween(list,4,3);
	printList(list);
	cout<<endl<<endl;
	list=deleteDuplicate(list);	
	printList(list);
}
	