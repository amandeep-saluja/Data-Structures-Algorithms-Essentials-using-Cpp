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
node *removeNode(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL or root->right == NULL)
    {
        node *temp = NULL;
        if (root->left != NULL)
            temp = root->left;
        if (root->right != NULL)
            temp = root->right;
        // delete (root);
        return temp;
    }
    cout << root->key << root->left->key << root->right->key << endl;
    node *l = removeNode(root->left);
    node *r = removeNode(root->right);
    if (l != NULL)
    {
        cout << "Shifting: " << root->left->key << " to " << l->key << endl;
        root->left = l;
    }
    if (r != NULL)
    {
        cout << "Shifting: " << root->right->key << " to " << r->key << endl;
        root->right = r;
    }
    return root;
}

vector<int> removeHalfNodes(node *root)
{
    vector<int> v;
    printInorder(root, v);
    root = removeNode(root);
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