#include <unordered_map>
using namespace std;

class Trie;

class Node
{
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

public:
    Node(int d)
    {
        data = d;
        isTerminal = false;
    }

    friend class Trie;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    // Insertion O[length of character]

    void insert(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                temp->m[ch] = new Node(ch);
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    // Searching O[length of character]

    bool search(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    // Deletion O[length of character]
};