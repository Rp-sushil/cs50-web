#include <iostream>
#include <stdlib.h>
using namespace std;

class circularQueue
{
public:
    int f = -1, r = -1;
    int A[10];
    void enqueue(int item);
    int deque();
    void display();
};

void circularQueue::enqueue(int item)
{
    f++;
    if (r == -1)
    {
        r++;
    }
    else if (f % 10 >= r && f > 9)
    {
        cout << "Warning::OverFlow" << endl;
        exit(1);
    }
    A[f] = item;
}
int circularQueue::deque()
{
    if (r == -1)
    {
        cout << "\nWarning::UnderFlow" << endl;
        exit(1);
    }
    else if (r > f)
    {
        cout << "\nWarning::UnderFlow" << endl;
        exit(1);
    }
    else
        return A[r++];
}
void circularQueue::display()
{
    for (int i = (r % 10); i <= (f % 10); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    circularQueue cq;
    int option = -1;
    while (option != 4)
    {
        cout << "1.enqueue" << endl;
        cout << "2.dequeue" << endl;
        cout << "3.display" << endl;
        cout << "4.exit" << endl;
        cout << "option := ";
        cin >> option;
        if (option == 1)
        {
            cout << "\nEnter element: ";
            int item;
            cin >> item;
            cq.enqueue(item);
        }
        else if (option == 2)
        {
            int pop = cq.deque();
            cout << "Popped element: " << pop;
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
