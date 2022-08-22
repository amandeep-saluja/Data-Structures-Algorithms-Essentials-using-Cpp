#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;

class Graph
{
    int V; // vertex
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int i, int j, int wt, bool undir = true)
    {
        l[i].push_back({wt, j});
        if (undir)
        {
            l[j].push_back({wt, i});
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
                cout << node.second << ",";
            }
            cout << endl;
        }
    }

    int dijkshtra(int src, int dest)
    {
        // Data structure
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        // init
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);

            // Iterate over the nbrs of node
            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (distTillNow + currentEdge < dist[nbr])
                {
                    // remove if nbr already exist in the set
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    // insert the updated value with the new dist
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // Single Source Shortest Dist to all other nodes
        for (int i = 0; i < V; i++)
        {
            cout << "Node i " << i << " Dist " << dist[i] << endl;
        }
        return dist[dest];
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkshtra(0, 4) << endl;

    return 0;
}