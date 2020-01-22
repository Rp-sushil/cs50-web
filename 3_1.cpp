#include<iostream>
using namespace std;

template <typename type>
class cirQueue{
	public:
		cirQueue(int);
		~cirQueue();
		bool enqueue(type item);
		bool dequeue(type& item);
		void display();
	private:
		type* data_value;
		int front, back;
		int capacity;
};

template <typename type>
cirQueue<type>::cirQueue(int cap){
	capacity = cap;
	data_value = new type[capacity];
	front = -1;
	back = -1;
}

template <typename type>
bool cirQueue<type>::enqueue(type item){
	if(back - front >=  capacity){
		cout<<"Waring::OverFlow\n";
		return false;
	}
	data_value[(++back) % capacity] = item;
	return true;
}

template <typename type>
bool cirQueue<type>::dequeue(type& item){
	if(front < back){
		item = data_value[++front];
		return true;
	}
	cout<<"Warning::UnderFlow\n";
	return false;
}

template <typename type>
void cirQueue<type>::display(){
	for(int i = (front + 1) % capacity; i <= back % capacity; i++){
		cout<<data_value[i]<<" ";
	}
	cout<<endl;
}
template <typename type>
cirQueue<type>::~cirQueue(){
	delete [] data_value;
}
	

int main()
{
    cirQueue<int> cq(5);
    int option = -1;
    while (option != 4)
    {
        cout << "1.enqueue\t";
        cout << "2.dequeue\t";
        cout << "3.display\t";
        cout << "4.exit" << endl;
        cout << "option := ";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter element: ";
            int item;
            cin >> item;
            cq.enqueue(item);
        }
        else if (option == 2)
        {
		int item; 
	    cq.dequeue(item);
        }
        else if (option == 3)
        {
            cout << "Queue: ";
            cq.display();
        }
        cout << endl;
    }
    return 0;
}
