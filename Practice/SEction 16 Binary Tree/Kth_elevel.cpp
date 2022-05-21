#include <bits/stdc++.h>
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

vector<int> printKthLevel(Node *root, int k)
{
    vector<int> v;

    if (root == NULL)
    {
        return v;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;

    while (count != k)
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            count++;
            q.push(NULL);
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

    while (q.front() != NULL)
    {
        v.push_back(q.front()->data);
        q.pop();
    }

    return v;
}

int sumOfKthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (level != k)
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            level++;
            q.push(NULL);
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

    while (q.front() != NULL)
    {
        sum += q.front()->data;
        q.pop();
    }

    return sum;
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
    for (int x : printKthLevel(root, 1))
    {
        cout << x << " ";
    }

    cout << endl;
    cout << sumOfKthLevel(root, 2);

    return 0;
}