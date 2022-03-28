// #include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    // Initializer list
    Node(int d) : data(d), next(nullptr) {}

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
        cout << "Deleting the node with data " << data << endl;
    }

    void setNext(Node *node)
    {
        this->next = node;
    }

    Node *getNext()
    {
        return this->next;
    }

    int getData()
    {
        return data;
    }

    void setData(int d)
    {
        data = d;
    }
};

class List
{
    Node *head;
    Node *tail;

    int searchHelper(int data, Node *n)
    {
        if (n == nullptr)
        {
            return -1;
        }
        if (n->getData() == data)
        {
            return 0;
        }

        int subIdx = searchHelper(data, n->getNext());
        if (subIdx == -1)
            return -1;
        else
            return subIdx + 1;
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List()
    {
        if (head != nullptr)
        {
            delete head;
        }
        cout << "Deleting the linked list" << endl;
    }

    Node *begin()
    {
        return head;
    }

    Node *end()
    {
        return tail;
    }

    void push_front(int data)
    {
        Node *n = new Node(data);
        if (head == nullptr)
        {
            head = tail = n;
        }
        else
        {
            n->setNext(head);
            head = n;
        }
    }

    void push_back(int data)
    {
        Node *n = new Node(data);
        if (tail == nullptr)
        {
            head = tail = n;
        }
        else
        {
            tail->setNext(n);
            tail = n;
        }
    }

    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            this->push_front(data);
        }

        Node *n = head;
        int jump = 0;
        while (n != nullptr)
        {
            jump++;
            if (jump == pos)
            {
                Node *newNode = new Node(data);
                newNode->setNext(n->getNext());
                n->setNext(newNode);
            }
            n = n->getNext();
        }
    }

    int search(int data)
    {
        Node *n = head;
        int index = 0;
        while (n != nullptr)
        {
            if (n->getData() == data)
            {
                return index;
            }
            index++;
            n = n->getNext();
        }
        return -1;
    }

    int recursiveSearch(int data)
    {
        return searchHelper(data, head);
    }

    int pop_front()
    {
        if (head == nullptr)
        {
            return -1;
        }

        Node *temp = head;
        head = head->getNext();
        temp->setNext(nullptr);
        int data = temp->getData();
        delete temp;
        return data;
    }

    void print()
    {
        Node *node = head;
        while (node != nullptr)
        {
            cout << node->getData() << " -> ";
            node = node->getNext();
        }
        cout << endl;
    }
};