#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data at left of " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter the data at right of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{

    Node *root = NULL;
    root = createTree(root);

    cout << endl
         << "Inorder traversal: ";
    inOrder(root);

    return 0;
}