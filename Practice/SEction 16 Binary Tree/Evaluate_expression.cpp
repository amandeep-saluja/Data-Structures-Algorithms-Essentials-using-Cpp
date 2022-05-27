#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string key;
    Node *left, *right;
    Node(string d)
    {
        this->key = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int evalTree(Node *root)
{
    cout << root->key << endl;
    if (root == NULL)
    {
        cout << "here ";
        return 0;
    }

    int a = evalTree(root->left);
    cout << root->key << " ";
    int b = evalTree(root->right);
    return a + b;
}

void printInorder(Node *root)
{
    cout << root->key << " ";
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(to_string(d));
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int main()
{
    // Node* root = new Node("+");
    // root->left = new Node("3");
    // root->right = new Node("*");
    // root->right->left = new Node("+");
    // root->right->left->left = new Node("5");
    // root->right->left->right = new Node("9");
    // root->right->right = new Node("2");
    Node *root = buildTree();

    // cout<<evalTree(root);
    printInorder(root);
    // cout<<"\n Hello"<<endl;
    return 0;
}