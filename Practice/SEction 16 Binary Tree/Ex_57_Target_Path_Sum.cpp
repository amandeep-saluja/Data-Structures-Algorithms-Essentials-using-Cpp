#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left, *right;
};

struct node *newnode(int data)
{
    struct node *nod = new node();
    nod->val = data;
    nod->left = nod->right = NULL;
    return nod;
}

void checkPathSum(node *root, int sum, vector<vector<int>> &v, vector<int> &s)
{
    if (root == NULL)
    {
        return;
    }

    // leaf node
    if (root->left == NULL and root->right == NULL)
    {
        s.push_back(root->val);
        if (sum == root->val)
        {
            v.push_back(s);
        }
        s.pop_back();
        return;
    }

    int curr = root->val;
    s.push_back(curr);
    checkPathSum(root->left, sum - curr, v, s);
    checkPathSum(root->right, sum - curr, v, s);
    s.pop_back();
}

vector<vector<int>> pathSum(node *root, int targetSum)
{
    vector<vector<int>> v;
    vector<int> k;
    checkPathSum(root, targetSum, v, k);
    return v;
}

int main()
{
    int sum = 21;

    /* Constructed binary tree is
             10
            / \
          8    2
         / \  / \
        3  5 2  9
    */
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    root->right->right = newnode(9);

    vector<vector<int>> path = pathSum(root, sum);

    if (path.size() > 0)
        cout
            << "There is a root-to-leaf path with sum " << sum << endl;
    else
        cout << "There is no root-to-leaf path with sum " << sum << endl;

    for (vector<int> x : path)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}