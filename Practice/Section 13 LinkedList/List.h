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

    int remove(int pos)
    {
        if (head == nullptr)
        {
            return -1;
        }

        if (pos == 1)
        {
            int d = head->getData();
            // Node *n = head;
            if (head->getNext() == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node *n = head;
                head = head->getNext();
                n->setNext(nullptr);
                delete n;
            }

            return d;
        }

        Node *n = head;
        Node *prev = nullptr;
        for (int jump = 1; n != nullptr; jump++)
        {
            if (jump == pos)
            {
                break;
            }
            prev = n;
            n = n->getNext();
        }
        if (n != nullptr)
        {
            int d = n->getData();
            prev->setNext(n->getNext());
            n->setNext(nullptr);
            delete n;
            return d;
        }
        return -1;
    }

    int pop_back()
    {
        if (head == nullptr)
        {
            return -1;
        }
        if (head->getNext() == nullptr)
        {
            int d = head->getData();
            delete head;
            head = nullptr;
            return d;
        }
        Node *secondLast = nullptr;
        Node *n = head;
        while (n->getNext() != nullptr)
        {
            secondLast = n;
            n = n->getNext();
        }

        int d = n->getData();
        secondLast->setNext(nullptr);
        delete n;
        return d;
    }

    void print()
    {
        Node *node = head;
        int count = 0;
        while (node != nullptr)
        {
            cout << node->getData() << " -> ";
            node = node->getNext();
            count++;
            if (count == 10)
                break;
        }
        cout << endl;
    }
};