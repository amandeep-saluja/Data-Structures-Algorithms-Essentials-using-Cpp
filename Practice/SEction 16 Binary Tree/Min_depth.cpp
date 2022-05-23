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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1 + max(h1, h2);
}

int minDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int minn = INT_MAX;
    int level = 1;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            level++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else if (temp->left == NULL and temp->right == NULL)
        {
            minn = min(minn, level);
            return level;
        }
        else
        {
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

    return minn;
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
    cout << endl;

    cout << minDepth(root);

    return 0;
}
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1