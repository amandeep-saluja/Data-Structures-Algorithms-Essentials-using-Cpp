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

class HDPair
{
public:
    int height;
    int diameter;
};

HDPair diameterOpt(Node *root)
{
    HDPair p;
    // base case
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    // recursive case
    HDPair left = diameterOpt(root->left);
    HDPair right = diameterOpt(root->right);

    // height at current level
    p.height = 1 + max(left.height, right.height);

    // p.diameter = max(p.height, max(left.diameter, right.diameter)); //wrong

    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;

    // diameter at current level
    p.diameter = max(D1, max(D2, D3));

    return p;
}

int main()
{
    Node *root = buildLevelOrderTree();

    cout << diameterOpt(root).diameter;

    return 0;
}
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
