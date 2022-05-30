#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInRange(node *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (k1 <= root->data and k2 >= root->data)
    {
        // call in both direction
        printInRange(root->left, k1, k2);
        cout << root->data << " ";
        printInRange(root->right, k1, k2);
    }
    else if (k2 <= root->data)
    {
        printInRange(root->left, k1, k2);
    }
    else
    {
        printInRange(root->right, k1, k2);
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

    printInRange(root, 2, 13);

    return 0;
}