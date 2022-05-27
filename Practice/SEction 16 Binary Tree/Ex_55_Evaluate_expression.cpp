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
    if (root->left == NULL and root->right == NULL)
    {
        return stoi(root->key);
    }

    int a = evalTree(root->left);
    int b = evalTree(root->right);
    if (root->key == "+")
        return a + b;
    else if (root->key == "-")
        return a - b;
    else if (root->key == "*")
        return a * b;
    else
        return a / b;
}

void printInorder(Node *root)
{
    // cout << root << "... " << endl;
    if (root == NULL)
    {
        // cout << root << "ending" << endl;
        return;
    }
    // cout << "calling left: " << endl;
    printInorder(root->left);
    // if (root == NULL)
    cout << root->key << "; ";
    // cout << "calling right: " << endl;
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
    Node *root = new Node("+");
    root->left = new Node("3");
    root->right = new Node("*");
    root->right->left = new Node("+");
    root->right->left->left = new Node("5");
    root->right->left->right = new Node("9");
    root->right->right = new Node("2");
    cout << evalTree(root) << endl;

    delete (root);

    root = new Node("+");
    root->left = new Node("*");
    root->left->left = new Node("5");
    root->left->right = new Node("-4");
    root->right = new Node("-");
    root->right->left = new Node("100");
    root->right->right = new Node("20");
    cout << evalTree(root) << endl;

    delete (root);

    root = new Node("+");
    root->left = new Node("*");
    root->left->left = new Node("5");
    root->left->right = new Node("4");
    root->right = new Node("-");
    root->right->left = new Node("100");
    root->right->right = new Node("/");
    root->right->right->left = new Node("20");
    root->right->right->right = new Node("2");

    cout << evalTree(root);
    return 0;
}