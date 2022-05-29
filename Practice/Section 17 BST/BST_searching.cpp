#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
    node(int data)
    {
        key = data;
        left = right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->key)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInorder(node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == data)
    {
        return true;
    }

    if (data < root->key)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{

    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    node *root = NULL;

    for (int x : arr)
    {
        root = insert(root, x);
    }

    printInorder(root);
    cout << endl;

    if (search(root, 1))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}