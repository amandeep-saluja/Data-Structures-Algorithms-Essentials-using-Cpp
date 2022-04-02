#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    node *head;
    node *tail;

    LinkedList() : head(NULL), tail(NULL) {}

    void insert(int data)
    {
        node *n = new node(data);
        if (tail == nullptr)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }
};

void print(node *head)
{
    node *n = head;
    int count = 0;
    while (n != NULL)
    {
        cout << n->data << " -> ";
        n = n->next;
        count++;
        if (count == 10)
            break;
    }
    cout << "NULL" << endl;
}

node *bubble_sort_LinkedList_itr(node *head)
{
    cout << "Starting sort" << endl;
    node *ptr;
    int swap = -1;
    while (swap != 0)
    {
        cout << "Outer Loop >" << endl;
        swap = 0;
        ptr = head;
        node *prev = NULL;
        while (ptr != NULL and ptr->next != NULL)
        {
            cout << "  > Inner Loop: prev:" << (prev != NULL) ? prev->data : -1 << ptr->data;
            if (ptr->data > ptr->next->data)
            {
                cout << "    > Swapping " << ptr->data << " & " << ptr->next->data << endl;
                swap = 1;
                node *nextNode = ptr->next;
                cout << "Prev(" << prev->next->data << ")-> " << nextNode->data << endl;
                prev->next = nextNode;
                cout << "ptr(" << ptr->data << ")->" << nextNode->next->data << endl;
                ptr->next = nextNode->next;
                cout << "nextNode(" << nextNode->data << ")->" << ptr->data << endl;
                nextNode->next = ptr;
                print(head);
                // ptr = prev->next;
            }
            else
                ptr = ptr->next;
            prev = ptr;
        }
        // break;
    }

    return head;
}

int main()
{
    LinkedList l;
    l.insert(10);
    l.insert(30);
    l.insert(20);
    l.insert(5);

    print(l.head);

    bubble_sort_LinkedList_itr(l.head);

    print(l.head);

    return 0;
}
