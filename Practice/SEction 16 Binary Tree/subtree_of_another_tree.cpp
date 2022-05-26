#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

bool compare(Node *root, Node *subRoot)
{
    if (root == NULL and subRoot == NULL)
    {
        return true;
    }

    if (root == NULL or subRoot == NULL)
    {
        return false;
    }

    if (root->data == subRoot->data)
    {
        bool l = compare(root->left, subRoot->left);
        bool r = compare(root->right, subRoot->right);
        return l and r;
    }
    else
        return false;
}

bool isSubTree(Node *root, Node *subRoot)
{
    if (subRoot == NULL)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }

    if (root->data == subRoot->data)
    {
        if (compare(root, subRoot))
        {
            return true;
        }
    }

    bool left = isSubTree(root->left, subRoot);
    bool right = isSubTree(root->right, subRoot);
    return left or right;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right = new Node(5);

    Node *subTree = new Node(4);
    subTree->left = new Node(1);
    subTree->right = new Node(2);

    cout << isSubTree(root, subTree);

    return 0;
}