#include<bits/stdc++.h>
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
struct list_item{
	Node *head;
	Node *tail;
};
list_item *array;

int find(Node *list, int key){
	int retval = 0;
	Node *temp = list;
	while(temp!=NULL){
		if(temp->data == key)
			return retval;
		temp = temp->next;
		retval++;
	}
	return -1;
}

void insert(int key,int value){
	cout<<"sabfyuasufgaeygfkugvjcf"<<endl;
	int index = key;
	Node *list = ::array[key].head;
	Node *item = new Node();
	item->data = value;
	item->next = NULL;
	if(list==NULL){
		cout<<"inserting list "<<key<<" "<<value<<endl;
		::array[key].head = item;
		::array[key].tail = item;
	}
	else{
		int find_index = find(list,key);
		cout<<find_index<<"asf"<<endl;
		if(find_index == -1){
			/*
				key not found in list
			*/
			::array[index].tail-> next = item;
			::array[index].tail = item;
		}
	}
}

void init_array(){
	int max = 10;
	for(int i=0; i<max; i++){
		::array[i].head = NULL;
		::array[i].tail = NULL;
	}
}

int main(){
	Node *list1 = NULL;
	Node *list2 = NULL;
	init_array();
	insert(5,1);
}