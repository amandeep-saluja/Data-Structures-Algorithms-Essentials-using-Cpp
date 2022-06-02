#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

bool checkBST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->key < min or root->key > max)
    {
        return false;
    }

    return checkBST(root->left, min, root->key - 1) and checkBST(root->right, root->key + 1, max);
}

Node *pre = NULL;

bool isBST(Node *root)
{
    // return checkBST(root, INT_MIN, INT_MAX);

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return false;
        }

        if (pre != NULL and root->key <= pre->key)
        {
            return false;
        }

        pre = root;

        return isBST(root->right);
    }
    return true;
}

void printInorder(Node *root)
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    printInorder(root);
    cout << endl;
    cout << "Is BST: " << isBST(root) << endl;

    root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    printInorder(root);
    cout << endl;
    cout << "Is BST: " << isBST(root) << endl;

    root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    printInorder(root);
    cout << endl;
    cout << "Is BST: " << isBST(root) << endl;

    return 0;
}

/*

WRONG

bool isBST(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool bst = true;
    if (root->left != NULL)
    {
        bst = bst and root->left->key < root->key;
    }
    if (root->right != NULL)
    {
        bst = bst and root->right->key > root->key;
    }
    if (!bst)
    {
        return false;
    }
    return bst and isBST(root->left) and isBST(root->right);
}

*/