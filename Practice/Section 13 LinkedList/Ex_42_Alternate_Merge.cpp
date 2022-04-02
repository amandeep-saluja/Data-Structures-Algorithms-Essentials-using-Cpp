#include <iostream>
#include "List.h"

Node *alternateMerge(Node *root1, Node *root2)
{
    Node *p1 = root1;
    Node *p2 = root2;

    Node *dummyNode = new Node(-1);
    Node *p3 = dummyNode;

    while (p1 != NULL and p2 != NULL)
    {
        p3->setNext(p1);
        p1 = p1->getNext();
        p3 = p3->getNext();

        p3->setNext(p2);
        p2 = p2->getNext();
        p3 = p3->getNext();
    }

    while (p1 != NULL)
    {
        p3->setNext(p1);
        p1 = p1->getNext();
    }

    while (p2 != NULL)
    {
        p3->setNext(p2);
        p2 = p2->getNext();
    }

    return dummyNode->getNext();
}

Node *alternateMergeRecursive(Node *node1, Node *node2)
{

    if (node1 == NULL)
    {
        return node2;
    }
    if (node2 == NULL)
    {
        return node1;
    }

    Node *head = node1;
    Node *p3 = head;
    Node *nextNode = node1->getNext();

    p3->setNext(node2);
    p3 = p3->getNext();
    p3->setNext(alternateMergeRecursive(nextNode, node2->getNext()));

    return head;
}