#include<iostream>
using namespace std;

template <typename type>
class queue{
	public:
		queue(int);
		~queue();
		bool enqueue(type item);
		bool dequeue(type& item);
		void display();
	private:
		type* data_value;
		int front, back, capacity;
};

template <typename type>
queue<type>::queue(int cap){
	capacity = cap;
	data_value = new type[capacity];
	front = 0;
	back = -1;
}

template <typename type>
bool queue<type>::enqueue(type item){
	if(back < capacity - 1){
		data_value[++back] = item;
		return true;
	}
	cout<<"Warning:: OverFlow\n";
	return false;
}

template <typename type>
bool queue<type>::dequeue(type& item){
	if(front <= back){
		item = data_value[front++];
		return true;
	}
	cout<<"Waring:: UnderFlow\n";
	return false;
}

template <typename type>
void queue<type>::display(){
	for(int i = front; i <= back; i++){
		cout<<data_value[i]<<" ";
	}
	cout<<endl;	
}

template <typename type>
queue<type>::~queue(){
	delete [] data_value;
}


int main()
{
	queue<int> q(3);
	int option = -1;
	while(option != 4){
		cout<<"1.Enqueue\t";
		cout<<"2.Dequeue\t";
		cout<<"3.Display\t";
		cout<<"4.Exit\n";
		cout<<"Option: ";
		cin>>option;
		if(option == 1){
			cout<<"Enter Item:";
			int item;
			cin>>item;
			q.enqueue(item);
		}
		else if(option == 2){
			int item;
			q.dequeue(item);
		}
		else if(option == 3){
			cout<<"Queue: ";
			q.display();
		}
		else{
			return 0;
		}
		cout<<endl;
	}
	return 0;
}

