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

// Preorder build of the tree -> Root, Left, Right Tree
Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void levelOrder(Node *root, queue<Node*> q)
{
    if (root == NULL)
    {
        return;
    }

    q.push(root);
    q.push(NULL);

    while (!q.empty() and q.front() != NULL)
    {
        while (q.front() != NULL)
        {
            cout << q.front()->data << " ";
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        q.pop();
        cout << endl;
        q.push(NULL);
    }
}

int main()
{
    Node *root = buildTree();
    queue<Node*> q;
    levelOrder(root, q);

    return 0;
}
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1