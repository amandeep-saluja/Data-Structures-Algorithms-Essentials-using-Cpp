#include <iostream>
#include "List.h"
using namespace std;

Node *alternateMerge(Node *root1, Node *root2)
{
    if (root1 == NULL or root2 == NULL)
    {
        return NULL;
    }

    Node *first = root1;
    Node *second = root2;
    Node *temp = NULL;

    while (first->getNext() != NULL and second->getNext() != NULL)
    {
        temp = first->getNext();
        first->setNext(second);
        first = temp;
        temp = second->getNext();
        second->setNext(first);
        second = temp;
        // first = first->getNext();
        // second = second->getNext();
    }

    if (first->getNext() == NULL)
    {
        first->setNext(second);
    }
    else if (second->getNext() == NULL)
    {
        // cout << "Hi";
        second->setNext(first);
    }
    // else if (first->getNext() == NULL)
    // {
    //     cout << "Here";
    //     first->setNext(second);
    // }

    return root1;
}

void print(Node *head)
{
    Node *node = head;
    int count = 0;
    while (node != nullptr)
    {
        cout << node->getData() << " -> ";
        node = node->getNext();
        count++;
        if (count == 15)
        {
            cout << "Had to break";
            break;
        }
    }
    cout << endl;
}

int main()
{

    List l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(5);
    l.push_back(7);
    l.push_back(9);

    // cout << l.search(4) << endl;
    // cout << l.search(1) << endl;
    // cout << l.search(6) << endl;
    // cout << l.search(99) << endl;

    // cout << l.recursiveSearch(4) << endl;
    // cout << l.recursiveSearch(1) << endl;
    // cout << l.recursiveSearch(6) << endl;
    // cout << l.recursiveSearch(99) << endl;

    l.print();

    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;

    // cout << "Pop back 1: " << l.pop_back() << endl;
    // cout << "Pop back 2: " << l.pop_back() << endl;
    // cout << "Pop back 3: " << l.pop_back() << endl;
    // cout << "Pop back 4: " << l.pop_back() << endl;
    // cout << "Pop back 5: " << l.pop_back() << endl;
    // cout << "Pop back 6: " << l.pop_back() << endl;

    // cout << l.remove(5) << endl;
    // l.reverse();
    // cout << "Mid: " << l.midOfLinklist() << endl;
    // cout << "Kth element: " << l.kthLastElement(4) << endl;

    // l.print();

    List l2;
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    l2.push_back(8);
    // l2.push_back(10);
    l2.print();

    Node *head = alternateMerge(l.begin(), l2.begin());

    cout << "Merging both list" << endl;

    print(head);

    return 0;
}