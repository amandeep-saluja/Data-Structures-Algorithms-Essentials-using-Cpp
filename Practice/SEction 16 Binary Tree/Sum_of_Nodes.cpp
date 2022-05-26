#include <iostream>
#include <queue>
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

int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftNodes = sumOfNodes(root->left);
    int rightNodes = sumOfNodes(root->right);
    return root->data + leftNodes + rightNodes;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right = new Node(3);
    root->right->right = new Node(6);

    cout << sumOfNodes(root);

    return 0;
}