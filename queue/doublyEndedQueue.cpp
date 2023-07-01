#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

class DoublyQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    DoublyQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void pushFront(int element)
    {
        if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1))
        {
            cout << "Queue is Full" << endl;
            return;
        }

        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = element;
        }

        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = element;
        }
        else
        {
            front--;
            arr[front] = element;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Elements in CircularQueue are: " << endl;
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << endl;
            }
        }
        else
        {
            for (int i = front; i < size; i++)
                cout << arr[i] << endl;

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << endl;
        }
    }
};

int main()
{
    DoublyQueue q(5);

    q.pushFront(1);
    q.pushFront(3);
    q.pushFront(5);

    q.display();

    // deque<int> qu;

    return 0;
}