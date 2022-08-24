#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> results;

void printAdjList(vector<vector<int>> graph)
{
    int V = graph.size();
    for (int i = 0; i < V; i++)
    {
        cout << i << "-->";
        for (int x : graph[i])
        {
            cout << x << ",";
        }
        cout << endl;
    }
}

void helper(vector<vector<int>> &graph, vector<int> v, int src, int des, vector<vector<int>> &results)
{
    v.push_back(src);
    if (src == des)
    {
        results.push_back(v);
        return;
    }

    for (int l : graph[src])
    {
        // v.push_back(l);
        helper(graph, v, l, des, results);
        // v.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> result;
    vector<int> m;
    // m.push_back(0);
    helper(graph, m, 0, graph.size() - 1, result);
    return result;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    for (auto x : allPathsSourceTarget(graph))
    {
        for (int x : x)
        {
            cout << x << "-->";
        }
        cout << endl;
    }

    return 0;
}
