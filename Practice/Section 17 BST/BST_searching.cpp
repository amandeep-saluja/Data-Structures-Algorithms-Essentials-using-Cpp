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

// Complexity : log N <= O[Height] <= M
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
    return search(root->right, data);
}

int main()
{

    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    node *root = NULL;

    for (int x : arr)
    {
        root = insert(root, x);
    }

    if (search(root, 1))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}