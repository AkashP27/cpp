#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  Node(int d)
  {
    this->data = d;
    this->prev = NULL;
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

void prependNode(Node *&head, Node *&tail, int d)
{

  if (head == NULL)
  {
    Node *temp = new Node(d);
    head = temp;
    tail = temp;
  }
  else
  {
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void appendNode(Node *&head, Node *&tail, int d)
{

  if (tail == NULL)
  {
    Node *temp = new Node(d);
    tail = temp;
    head = temp;
  }
  else
  {
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
  // Insert at first position
  if (position == 1)
  {
    prependNode(head, tail, d);
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
    appendNode(head, tail, d);
    return;
  }

  Node *nodeToInsert = new Node(d);

  nodeToInsert->next = temp->next;
  temp->next->prev = nodeToInsert;
  temp->next = nodeToInsert;
  nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
  if (position == 1)
  {
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;

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

    // Deleting last node
    if (current->next == NULL)
    {
      current->prev = NULL;
      previous->next = current->next;
      current->next = NULL;

      tail = previous; // To get tail value

      delete current;
      return;
    }

    // Deleting inbetween nodes
    current->prev = NULL;
    previous->next = current->next;
    current->next->prev = previous;
    current->next = NULL;

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
  cout << endl;
}

int getLength(Node *head)
{
  Node *temp = head;
  int length = 0;

  while (temp != NULL)
  {
    length++;
    temp = temp->next;
  }

  return length;
}

int main()
{

  // Node* node = new Node(5);
  Node *head = NULL;
  Node *tail = NULL;

  // prependNode(head, 6);
  // prependNode(head, 7);

  appendNode(head, tail, 8);
  appendNode(head, tail, 9);
  appendNode(head, tail, 10);
  appendNode(head, tail, 15);

  print(head);

  // insertAtPosition(head , tail, 4, 99);
  // print(head);

  deleteNode(head, tail, 4);
  print(head);

  cout << getLength(head) << endl;

  cout << "head = " << head->data << endl;
  cout << "tail = " << tail->data << endl;

  return 0;
}