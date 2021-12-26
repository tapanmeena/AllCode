#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void print_list(Node *node){
	while(node!=NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
}

void insert_node(Node **node, int data){
	Node * nNode = new Node;
	nNode->data = data;
	nNode->next = NULL;
	if(*node == NULL){
		*node = nNode;
		return;
	}
	Node *temp = *node;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = nNode;
}

void print_intersection(map<int,int> all){
	cout<<"Printing Intersection ";
	for(auto it = all.begin(); it != all.end(); it++)
		if(it->second>1)
			cout<<it->first<<" ";
	cout<<endl;
}

void print_union(map<int,int> all){
	cout<<"Printing Union ";
	for(auto it = all.begin(); it != all.end(); it++)
		if(it->second>0)
			cout<<it->first<<" ";
	cout<<endl;
}

void print_intersection_union(Node *list1, Node *list2){
	map<int,int> all;
	//traverse first list
	Node *temp = list1;
	while(temp!=NULL){
		all[temp->data]++;
		temp = temp->next;
	}
	//traverse second list
	temp = list2;
	while(temp!= NULL){
		all[temp->data]++;
		temp = temp->next;
	}
	print_intersection(all);
	print_union(all);
}

int main(){
	Node *list1 = NULL;
	Node *list2 = NULL;
	int arr1[] = {1,2,3,4,5,6};
	int arr2[] = {1,2,3,7,9,2,7,5};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	// insert_array(&list1, arr1);
	for(int i=0; i<m; i++)
		insert_node(&list1, arr1[i]);
	for(int i=0; i<n; i++)
		insert_node(&list2, arr2[i]);

	print_intersection_union(list1,list2);
	return 0;
}