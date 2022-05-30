#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void leaf_to_node(node *root, vector<int> &s)
{
    if (root == NULL)
    {
        return;
    }

    // leaf node
    if (root->left == NULL and root->right == NULL)
    {
        s.push_back(root->data);
        for (int y : s)
        {
            cout << y << " -> ";
        }
        cout << endl;
        // backtracking step
        s.pop_back();
        return;
    }

    s.push_back(root->data);
    leaf_to_node(root->left, s);
    leaf_to_node(root->right, s);
    // backtracking step
    s.pop_back();
}

int main()
{
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    node *root = NULL;

    for (int x : arr)
    {
        root = insert(root, x);
    }

    vector<int> v;

    leaf_to_node(root, v);

    return 0;
}