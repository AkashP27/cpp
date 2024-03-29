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

void createTreeLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void morrisInorderTraversal(Node *root)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            Node *predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

void morrisPreorderTraversal(Node *root)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            Node *predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                cout << current->data << " ";
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        root = s.top();
        s.pop();

        cout << root->data << " ";
        if (root->right)
            s.push(root->right);

        if (root->left)
            s.push(root->left);
    }
}

void inorderTraversal(Node *root)
{
    // if (root == NULL)
    //     return;

    stack<Node *> s;
    Node *node = root;

    while (true)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if (s.empty())
                break;
            node = s.top();
            s.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if (root->left)
            s1.push(root->left);

        if (root->right)
            s1.push(root->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{

    Node *root = NULL;

    // createTreeLevelOrder(root);
    root = createTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl
         << "Morris Inorder Traversal : ";
    morrisInorderTraversal(root);

    cout << endl
         << "Morris PreOrder Traversal : ";
    morrisPreorderTraversal(root);

    cout << endl
         << "Inorder traversal: ";
    inOrder(root);

    cout << endl
         << "Preorder traversal: ";
    preOrder(root);

    cout << endl
         << "Postorder traversal: ";
    postOrder(root);

    cout << endl
         << "Iterative Preorder traversal: ";
    preorderTraversal(root);

    cout << endl
         << "Iterative Inorder traversal: ";
    inorderTraversal(root);

    cout << endl
         << "Iterative Postorder traversal: ";
    postorderTraversal(root);

    return 0;
}