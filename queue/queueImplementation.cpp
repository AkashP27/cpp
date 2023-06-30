#include<iostream>
using namespace std;

class Queue{

    public:
        int *arr;
        int size;
        int front;
        int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = 0;
    }

    void enque(int element){
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = element;
            rear++;
        }
    }

    void deque(){
        if(front == rear){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            for(int i=0; i<rear-1; i++){
                arr[i] = arr[i+1];
            }
            rear--;
        }
    }

    int frontElement(){
        int ans = 0;
        if (front == rear){
            cout << "Queue is Empty" << endl;
        }
        else{
            ans = arr[front];
        }
        return ans;
    }

    bool isEmpty(){
        if (front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void display(){
        if (front == rear){
            cout << "Queue is Empty" << endl;
        }
        else{
            for (int i = front; i < rear; i++){
                cout<< arr[i] << endl;
            }
        }
    }
};

int main(){

    Queue q(5);

    q.enque(10);
    q.enque(11);
    q.enque(12);
    q.enque(13);
    q.enque(14);

    q.deque();
    q.deque();

    cout<<"Front Element: "<<q.frontElement()<<endl;

    if(q.isEmpty()){
        cout<<"Empty Queue"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

    q.display();

    return 0;
}