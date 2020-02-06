#include<iostream>
#include<cstdlib>
using namespace std;


template<typename type>
struct node{
	type item;
	node* next;
};

template<typename type>
class stack{
	public:
		bool empty();
		stack();
		type top();
		void push(type item);
		void pop();
		void display();
	private:
		node<type>* Top;
};

template<typename type>
stack<type>::stack(){
	Top = NULL;
}

template<typename type>
bool stack<type>::empty(){
	if(Top == NULL)
		return true;
	else
		return false;
}

template<typename type>
type stack<type>::top(){
	if(Top != NULL)
		return Top->item;
	else
		exit(1);
}

template<typename type>
void stack<type>::push(type item){
	node<type>* newNode = new node<type>;
	newNode->item = item;
	newNode->next = Top;
	Top = newNode;
}

template<typename type>
void stack<type>::pop(){
	if(!empty()){
		node<type>* newNode;
		newNode = Top;
		Top = Top->next;
		delete newNode;
	}
	else{
		cout<<"Error::underFlow"<<endl;
		exit(1);
	}
}

template<typename type>
void stack<type>::display(){
	node<type>* current = Top;
	while(current != NULL){
		cout<<current->item<<" ";
		current = current->next;
	}
	cout<<endl;
}


int main(){
	stack<int> s;
	s.push(4);
	s.push(5);
	s.display();
	s.push(6);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	s.display();
	cout<<s.empty()<<endl;
	return 0;

}
