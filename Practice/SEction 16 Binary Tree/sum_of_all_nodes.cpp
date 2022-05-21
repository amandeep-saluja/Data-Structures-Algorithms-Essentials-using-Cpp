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

int sumBT(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->data + sumBT(root->left) + sumBT(root->right);
}
Node *buildLevelOrderTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    queue<Node *> q;
    Node *root = new Node(d);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cin >> d;
        if (d != -1)
        {
            Node *p = new Node(d);
            temp->left = p;
            q.push(p);
        }
        cin >> d;
        if (d != -1)
        {
            Node *p = new Node(d);
            temp->right = p;
            q.push(p);
        }
    }

    return root;
}

int main()
{
    Node *root = buildLevelOrderTree();

    cout << sumBT(root) << endl;

    return 0;
}