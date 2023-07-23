#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            return;
        }
    }

    void deleteFromHeap()
    {
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index < size)
        {
            int leftChildIndex = 2 * index;
            int rightChildIndex = 2 * index + 1;

            if (leftChildIndex < size && arr[index] < arr[leftChildIndex])
            {
                swap(arr[index], arr[leftChildIndex]);
                index = leftChildIndex;
            }

            else if (rightChildIndex < size && arr[index] < arr[rightChildIndex])
            {
                swap(arr[index], arr[rightChildIndex]);
                index = rightChildIndex;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;

    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "array after heap" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}