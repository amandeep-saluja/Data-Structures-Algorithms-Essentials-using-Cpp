#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &rooms)
{
    int totalRooms = rooms.size();
    vector<bool> keysFound(totalRooms, false);
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int room = q.front();
        cout << room << "-->";
        q.pop();

        for (int key : rooms[room])
        {
            if (!keysFound[key])
            {
                q.push(key);
                keysFound[key] = true;
            }
        }
    }

    for (int i = 1; i < totalRooms; i++)
    {
        if (!keysFound[i])
        {
            return false;
        }
    }

    return true;
}

void dfs(vector<vector<int>> *rooms, int i, bool *visited)
{
    // cout << i << "-->";

    for (int key : rooms->at(i))
    {
        if (!visited[key])
        {
            visited[key] = true;
            // cout << key << " set to true" << endl;
            dfs(rooms, key, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    // return bfs(rooms);
    int totalRooms = rooms.size();
    bool *visited = new bool[totalRooms]{0};
    visited[0] = true;
    dfs(&rooms, 0, visited);
    for (int i = 0; i < totalRooms; i++)
    {
        if (!visited[i])
        {
            // cout << "Failed at " << i << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    // vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};

    if (canVisitAllRooms(rooms))
    {
        cout << "\nAll Room are open." << endl;
    }
    else
    {
        cout << "\nKey not present" << endl;
    }

    return 0;
}