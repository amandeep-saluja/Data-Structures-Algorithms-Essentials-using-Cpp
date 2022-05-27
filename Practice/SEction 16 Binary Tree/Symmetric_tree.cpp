#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
};

bool compareTree(Node *leftNode, Node *rightNode)
{
    if (leftNode == NULL and rightNode == NULL)
    {
        return true;
    }
    if (leftNode == NULL or rightNode == NULL)
    {
        return false;
    }

    bool node = leftNode->key == rightNode->key;

    return node and compareTree(leftNode->left, rightNode->right) and compareTree(leftNode->right, rightNode->left);
}

bool isSymmetric(Node *root)
{
    if (root == NULL)
    {
        return false;
    }

    return compareTree(root->left, root->right);
}
