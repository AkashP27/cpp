#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *next;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  ~Node()
  {
    // int value = this->data;
    if (this->next != NULL)
    {
      // delete next;
      this->next = NULL;
    }
  }
};

void prependNode(Node *&head, int d)
{

  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

void appendNode(Node *&tail, int d)
{
  Node *temp = new Node(d);

  tail->next = temp;
  tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

  // Insert at first position
  if (position == 1)
  {
    prependNode(head, d);
    return;
  }

  Node *temp = head;
  int i = 1;

  while (i < position - 1)
  {
    temp = temp->next;
    i++;
  }

  // Insert at last position
  if (temp->next == NULL)
  {
    appendNode(tail, d);
    return;
  }

  Node *nodeToInsert = new Node(d);

  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
  if (position == 1)
  {
    Node *temp = head;
    head = head->next;
    // temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *current = head;
    Node *previous = NULL;

    int i = 1;
    while (i < position)
    {
      previous = current;
      current = current->next;
      i++;
    }

    // deleting last node
    if (current->next == NULL)
    {
      previous->next = current->next;
      tail = previous; // To get tail  value
      delete current;

      return;
    }

    // Deleting Inbetween node
    previous->next = current->next;
    // current->next = NULL;
    delete current;
  }
}

void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  // cout << endl;
}

int main()
{

  Node *node = new Node(5);
  // cout << node->data << endl;
  // cout << node->next << endl;

  Node *head = node;
  Node *tail = node;

  // prependNode(head, 10);
  // prependNode(head, 15);

  appendNode(tail, 15);
  appendNode(tail, 10);
  appendNode(tail, 30);
  appendNode(tail, 40);

  // insertAtPosition(head, tail, 4, 30);

  print(head);

  cout << endl;

  deleteNode(head, tail, 4);

  print(head);
  cout << endl;

  cout << "head = " << head->data << endl;
  cout << "tail = " << tail->data << endl;

  return 0;
}