#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
    node(int d)
    {
        key = d;
        left = NULL;
        right = NULL;
    }
};

void printInorder(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left, v);
    v.push_back(root->key);
    printInorder(root->right, v);
}

vector<int> removeHalfNodes(node *root)
{
    vector<int> v;
    printInorder(root, v);
    return v;
}

int main()
{
    node *root = new node(2);
    root->left = new node(7);
    root->left->right = new node(6);
    root->left->right->left = new node(1);
    root->left->right->right = new node(11);
    root->right = new node(5);
    root->right->right = new node(9);
    root->right->right->left = new node(4);

    for (int x : removeHalfNodes(root))
    {
        cout << x << " ";
    }

    return 0;
}