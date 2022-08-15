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

public:
    HashTable(int default_size = 10)
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
    }
};