#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int V; // vertex
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = false)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        // Iterate over all the rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            // every element of the ith linked list
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void topological_sort()
    {
        vector<int> indegree(V, 0);

        // Iterate over all the vertex or nodes to find the right indegree
        for (int i = 0; i < V; i++)
        {
            for (int nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        // bfs
        queue<int> q;
        // Init the queue with nodes having 0 indegree
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int f = q.front();
            cout << f << "-->";
            q.pop();

            for (int nbr : l[f])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.topological_sort();

    return 0;
}