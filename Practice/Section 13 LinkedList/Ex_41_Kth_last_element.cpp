#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int kthLastElement(node *head, int k)
{
    if (head == nullptr)
    {
        return -1;
    }

    node *fast = head;
    node *slow = head;

    for (int i = 1; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

