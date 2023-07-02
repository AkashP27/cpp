#include <iostream>
using namespace std;

class CirDeque
{

public:
    int *arr;
    int size;
    int front;
    int rear;

    CirDeque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void enque(int element)
    {
        if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1))
        {
            cout << "Queue is Full" << endl;
            return;
        }
        // To insert first element
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = element;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = element;
        }
        else
        {
            rear++;
            arr[rear] = element;
        }
    }

    int deque()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
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

    CirDeque q(5);

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);

    q.deque();
    q.deque();

    q.display();

    return 0;
}