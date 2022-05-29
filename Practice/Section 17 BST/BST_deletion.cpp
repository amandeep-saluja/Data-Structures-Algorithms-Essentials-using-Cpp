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

void printInorder(node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

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

node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *remove(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->key)
    {
        root->left = remove(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = remove(root->right, data);
    }
    else
    {

        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    return root;
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

    root = remove(root, 14);

    printInorder(root);
    cout << endl;

    return 0;
}