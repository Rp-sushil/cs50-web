#include<iostream>
#include<cstdlib>
using namespace std;

template<typename type>
struct node{
	type item;
	node* next;
	node* prev;
};

template<typename type>
class queue{
	public:
		queue();
		void push(type item);
		void pop();
		type first();
		type last();
		void display();
	private:
		node<type>* First;
		node<type>* Last;
};

template<typename type>
queue<type>::queue(){
	First = NULL;
	Last = NULL;
}

template<typename type>
void queue<type>::push(type item){
	node<type>* newNode = new node<type>;
        newNode->next = Last;
	newNode->item = item;
	newNode->prev = NULL;
	if(Last != NULL)
		Last->prev = newNode;
	Last = newNode;
	if(First == NULL)
		First = newNode;
}

template<typename type>
void queue<type>::pop(){
	
	node<type>* current;
	current = First;
	if(First == Last){
		Last = NULL;
		First = NULL;
	}
	else{
		First = First->prev;
		First->next = NULL;
	}
	delete current;
}

template<typename type>
type queue<type>::first(){
	return First->item;
}

template<typename type>
type queue<type>::last(){
	return Last->item;
}

template<typename type>
void queue<type>::display(){
	node<type>* current = First;
	while(current != NULL){
		cout<<current->item<<" ";
		current = current->prev;
	}
	cout<<endl;
}

int main()
{
	queue<int> q;
	q.push(1);		
	q.push(3);		
	q.push(4);
	q.display();		// 1 3 4
	cout<<q.first()<<endl;	// 1
	cout<<q.last()<<endl;	// 4
	q.pop();		// 
	q.pop();
	q.display();		// 4
	q.pop();
	q.push(-7);	
	q.display();		// -7
	return 0;
}

