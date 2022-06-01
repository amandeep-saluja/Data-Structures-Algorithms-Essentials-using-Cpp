#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;

    node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

node *mirrorBST(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL and root->right == NULL)
    {
        return root;
    }
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBST(root->left);
    mirrorBST(root->right);
    return root;
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

void printInorder(node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
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
    root = mirrorBST(root);

    printInorder(root);

    return 0;
}