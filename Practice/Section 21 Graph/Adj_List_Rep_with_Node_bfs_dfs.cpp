#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    list<string> nbrs;

    Node(string d)
    {
        data = d;
    }
};

// Adjaceny list representation with Node
class Graph
{
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (string city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string source, string destination, bool undir = true)
    {
        m[source]->nbrs.push_back(destination);
        if (undir)
        {
            m[destination]->nbrs.push_back(source);
        }
    }

    void printGraph()
    {
        for (auto node : m)
        {
            cout << node.first << "-->";
            for (string city : node.second->nbrs)
            {
                cout << city << ",";
            }
            cout << endl;
        }
    }

    void bfs(string source)
    {
        queue<string> q;
        q.push(source);
        unordered_map<string, bool> visited;
        visited[source] = true;

        while (!q.empty())
        {
            string front = q.front();
            cout << front << "-->";
            q.pop();

            list<string> nbrs = this->m[front]->nbrs;

            for (string city : nbrs)
            {
                if (visited.count(city) == 0)
                {
                    q.push(city);
                    visited[city] = true;
                }
            }
        }
    }

    void dfsHelper(string source, unordered_set<string> *visited)
    {
        cout << source << "-->";

        for (string nbr : m[source]->nbrs)
        {
            if (visited->count(nbr) == 0)
            {
                visited->insert(nbr);
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(string source)
    {
        unordered_set<string> *visited = new unordered_set<string>;
        visited->insert(source);
        dfsHelper(source, visited);
    }
};

int main()
{

    vector<string> cities = {"Delhi", "New York", "Sydney", "Singapore", "Kota", "Pune"};

    Graph g(cities);
    g.addEdge("Delhi", "Kota");
    g.addEdge("Delhi", "Pune");
    g.addEdge("New York", "Sydney");
    g.addEdge("Sydney", "Singapore");
    g.addEdge("Singapore", "Delhi");
    g.addEdge("Pune", "New York");

    g.printGraph();
    cout << "\n---------- BFS ----------" << endl;

    g.bfs("Pune");

    cout << "\n----------- DFS ----------" << endl;

    g.dfs("Pune");

    return 0;
}