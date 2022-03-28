// List header file
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    // Initializer list
    Node(int d) : data(d), next(nullptr) {}

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

public:
    List() : head(nullptr), tail(nullptr) {}

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

    void print()
    {
        Node *node = head;
        while (node != nullptr)
        {
            cout << node->getData() << " -> ";
            node = node->getNext();
        }
    }
};