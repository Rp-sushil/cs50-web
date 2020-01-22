#include<iostream>
using namespace std;
template <typename type>
class stack {
	public:
		stack(int cap);
		~stack();
		bool push(type);
		bool pop(type&);
		void display();
		bool isPlaindrome();
	private:
		int top;
		int capacity;
		type* data_value;
};

template <typename type>
stack<type>::stack(int cap){
        capacity = cap;
	data_value = new type[capacity];
	top = -1;
}

template <typename type>
bool stack<type>::push(type item){
	if( top < capacity - 1){
		data_value[++top] = item;
		return true;
	}
	cout<<"\nWarning:: Overflow\n";
	return false;
}

template <typename type>
bool stack<type>::pop(type& item){
	if(top >= 0){
		item = data_value[top--];
		return true;
	}
	cout<<"\nWaring:: Underflow\n";
	return false;
}

template <typename type>
void stack<type>::display(){
	for(int i = 0; i <= top; i++){
		cout<<data_value[i]<<" ";
	}
	cout<<endl;
}

template <typename type>
bool stack<type>::isPlaindrome(){
	if(top == -1)
		return false;

	int i = 0;
	while(i <= top/2){
		if( data_value[i] != data_value[top - i])
			return false;
		i++;
	}
	return true;
}

template <typename type>
stack<type>::~stack(){
	delete [] data_value;
}


int main()
{
	stack<int> s(5);
	int option = 0;
	while(option != 5){
		cout<<"1.Push\t";
		cout<<"2.Pop\t";
		cout<<"3.Display\t";
		cout<<"4.IsPlaindrome\t";
		cout<<"5.Exit\n";
		cout<<"Option: ";
		cin>>option;
		if(option == 1){
			int item;
			cout<<"Enter item: ";
			cin>>item;
			s.push(item);
		}
		else if(option == 2){
			int item;
			s.pop(item);
		}
		else if(option == 3){
			cout<<"Stack: ";
			s.display();
		}
		else if(option == 4){
			if(s.isPlaindrome())
				cout<<"Stack is Plaindrome\n";
			else
				cout<<"Stack is not Plaindrome\n";
		}
		else{
			return 0;
		}
		cout<<endl;
	}
	return 0;
}

