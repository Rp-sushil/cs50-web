#include<iostream>
using namespace std;

struct node{
	int item;
	node* next;
};

class createLinkedList{
	public:
		createLinkedList();
		void insert(int item);
		void insert(int item, int position);
		void del();
		void del(int position);
		void display();
	private:
		node* head;
};

createLinkedList::createLinkedList(){
	head = NULL;
}

void createLinkedList::insert(int item){
	if(head == NULL){
		node* newNode;
		newNode = new node;
		newNode->item = item;
		newNode->next = NULL;
		head = newNode;
	}
	else{
		node* current;
		current = head;
		while(current->next != NULL){
			current = current->next;
		}
		node* newNode;
		newNode = new node;
		newNode->item = item;
		newNode->next = NULL;
		current->next = newNode;
	}
}
void createLinkedList::insert(int item, int position){
	int counter = 0;
	node* current;
	current = head;
	
	while(current->next->next != NULL){
		counter++;
		if(counter == position)
			break;
		current = current->next;
	}
	node* newNode;
	newNode = new node;
	newNode->item = item;
	newNode->next = current->next;
	current->next = newNode;
}
	
void createLinkedList::del(){
	node* current;
	current = head;
	if(current->next == NULL){
		delete current;
		head = NULL;
		return ;
	}
	while(current->next->next != NULL){
		current = current->next;
	}
	node* newNode = current->next;
	delete newNode;
	current->next = NULL;
}
void createLinkedList::del(int position){
	int counter = 0;
	node* current;
	current = head;
	while(current->next->next != NULL){
		counter++;
		if(counter == position)
			break;
		current = current->next;
	}
	node* newNode = current->next;
	current->next = current->next->next;
	delete newNode;
}
void createLinkedList::display(){
	node* current;
	current = head;
	while(current != NULL){
		cout<<current->item<<" ";
		current = current->next;
	}
	cout<<endl;
}

int main()
{
	createLinkedList linkedlist;
	linkedlist.insert(1);
	linkedlist.display();		// 1
	linkedlist.insert(2);
	linkedlist.display();		// 1 2
	linkedlist.insert(3);
	linkedlist.display();		// 1 2 3
	linkedlist.insert(4, 1);	
	linkedlist.display();		// 1 4 2 3
	linkedlist.del();
	linkedlist.display();		// 1 4 2 
	linkedlist.del(1);
	linkedlist.display();		// 1 2
	linkedlist.del();
	linkedlist.display();		// 1
	linkedlist.del();
	linkedlist.display();		// 2
	return 0;
}



