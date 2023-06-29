#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }

  ~Node()
  {
    if (this->next != NULL)
    {
      this->next = NULL;
    }
  }
};

void insertNode(Node *&tail, int element, int d)
{

  // Empty list
  if (tail == NULL)
  {
    Node *temp = new Node(d);
    tail = temp;
    temp->next = temp; // pointing to itself
  }
  else
  {
    // Non empty
    Node *current = tail;

    while (current->data != element)
    {
      current = current->next;
    }

    // current element representing element node
    Node *temp = new Node(d);

    temp->next = current->next;
    current->next = temp;
  }
}

void deleteNode(Node *&tail, int value)
{
  // Empty List
  if (tail == NULL)
  {
    cout << "List is already empty!" << endl;
    return;
  }
  else
  {
    Node *previous = tail;
    Node *current = previous->next;

    while (current->data != value)
    {
      previous = current;
      current = current->next;
    }

    previous->next = current->next;

    // deleting 1 node
    if (current == previous)
    {
      tail == NULL;
    }

    // delelting >=2 nodes
    else if (tail == current)
    {
      tail = previous;
    }

    current->next = NULL;
    delete current;
  }
}

void print(Node *tail)
{
  Node *temp = tail;

  if (tail == NULL)
  {
    cout << "List is empty!" << endl;
    return;
  }

  do
  {
    cout << tail->data << " ";
    tail = tail->next;
  } while (tail != temp);

  cout << endl;
}

int main()
{

  Node *tail = NULL;

  insertNode(tail, 5, 3);
  // insertNode(tail, 5, 7);
  // insertNode(tail, 7, 9);
  // insertNode(tail, 9, 11);
  // insertNode(tail, 11, 10);

  print(tail);

  deleteNode(tail, 3);
  print(tail);

  return 0;
}