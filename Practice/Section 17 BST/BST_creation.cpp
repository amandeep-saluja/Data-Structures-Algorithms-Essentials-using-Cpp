#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
    node(int data)
    {
        key = data;
        left = right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->key)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInorder(node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            // insert a new null for the next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->key << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{

    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    node *root = NULL;

    for (int x : arr)
    {
        root = insert(root, x);
    }

    printInorder(root);
    cout << endl;
    levelOrder(root);

    return 0;
}

/*


node *insert(node *root, int data)
{
    node *newNode = new node(data);
    node *temp = root;
    if (root == NULL)
    {
        return newNode;
    }
    while (temp->left != NULL and temp->right != NULL)
    {
        if (data < temp->key)
        {
            temp = temp->left;
        }
        else if (data > temp->key)
        {
            temp = temp->right;
        }
    }
    if (data < temp->key)
    {
        temp->left = newNode;
    }
    else
    {
        temp->right = newNode;
    }

    return root;
}

*/