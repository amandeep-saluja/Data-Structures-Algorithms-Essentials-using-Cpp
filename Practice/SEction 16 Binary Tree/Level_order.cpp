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

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
            cout << temp->data << " ";
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
    Node *root = buildLevelOrderTree();
    levelOrder(root);

    return 0;
}
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

/*

void levelOrder(Node *root)
{
    queue<Node *> q;
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

*/