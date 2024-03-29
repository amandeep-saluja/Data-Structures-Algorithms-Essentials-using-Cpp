#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    // deletes the next node before deleting the present node
    ~Node()
    {
        if (this->next != NULL)
        {
            delete this->next;
        }
    }
};

template <typename T>
class HashTable
{
    Node<T> **table;
    int cs; // total entries that have been inserted
    int ts; // size of the table

    int hashFunction(string key)
    {
        int idx = 0;
        int power = 1;

        for (char c : key)
        {
            idx = (idx + power * c) % ts;
            power = (power * 29) % ts;
        }

        return idx;
    }

    void rehash()
    {
        // save the pointer to old table and we will do insertions in new table
        Node<T> **oldTable = this->table;
        int oldTs = this->ts;
        this->cs = 0;

        // increase the table size
        this->ts = 2 * this->ts + 1;
        this->table = new Node<T> *[this->ts]; // you should make it prime

        for (int i = 0; i < this->ts; i++)
        {
            this->table[i] = NULL;
        }

        // copy elements from oldTable to new table
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;
                this->insert(key, value);
                temp = temp->next;
            }

            // deletes the ith Linked List
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    T &operator[](string key)
    {
        // return the value
        // if key is not found then create a new node and return
        // return the existing node

        T *valueFound = this->search(key);
        if (valueFound == NULL)
        {
            T object;
            this->insert(key, object);
            valueFound = this->search(key);
        }

        return *valueFound;
    }

    HashTable(int default_size = 7)
    {
        this->cs = 0;
        this->ts = default_size;

        this->table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
        {
            this->table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        // Insertion at head of the linked list

        int idx = this->hashFunction(key);
        Node<T> *n = new Node<T>(key, value);
        n->next = this->table[idx];
        this->table[idx] = n;
        cs++;

        float load_factor = cs / float(ts);
        if (load_factor > 0.7)
        {
            this->rehash();
        }
    }

    void print()
    {
        // Iterate over buckets
        for (int i = 0; i < this->ts; i++)
        {
            Node<T> *temp = this->table[i];
            cout << "Bucket " << i << "->";
            while (temp != NULL)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool isPresent(string key)
    {
        int idx = this->hashFunction(key);

        Node<T> *temp = this->table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    T *search(string key)
    {
        int idx = this->hashFunction(key);

        Node<T> *temp = this->table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key)
    {
        int idx = this->hashFunction(key);

        Node<T> *temp = this->table[idx];
        Node<T> *prev = NULL;

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (prev == NULL)
                {
                    this->table[idx] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                // remove the reference to next node
                // otherwise that will also be deleted while deleting the current node
                temp->next = NULL;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

/*
Insertion at tail
get the idx through hash function
check whether we have a Node created at the idx
if so place the value at the end of node
else create a new node and pass the address of node to hashtable's idx

int idx = this->hashFunction(key);
if (this->table[idx] != NULL)
{
    Node<T> *temp = this->table[idx];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node<T>(key, value);
}
else
{
    this->table[idx] = new Node<T>(key, value);
}
*/