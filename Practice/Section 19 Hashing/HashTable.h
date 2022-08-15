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
};