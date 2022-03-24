#include <bits/stdc++.h>
using namespace std;

void printMaze(vector<vector<int>> path)
{
    for (vector<int> p : path)
    {
        for (int x : p)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool helper(vector<vector<int>> &path, vector<string> &arr, int i, int j)
{
    // cout << "i: " << i << " j: " << j << endl;
    // base case
    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        path[i][j] = 1;
        printMaze(path);
        return false;
    }else if(i>arr.size()-1 or j>arr[0].size()-1) {
        return false;
    }

    // recursive case
    if (arr[i][j] == 'X')
    {
        return false;
    }

    path[i][j] = 1;
    bool isEmpty = helper(path, arr, i, j + 1);
    if (isEmpty)
        return true;

    isEmpty = helper(path, arr, i + 1, j);
    if (isEmpty)
        return true;
    path[i][j] = 0;
    return false;
}

vector<vector<int>> ratAndMice(vector<string> arr)
{
    vector<vector<int>> path(arr.size(), vector<int>(arr[0].size(), 0));
    helper(path, arr, 0, 0);
    return path;
}

int main()
{

    vector<string> arr = {
        "0X00",
        "000X",
        "X0X0",
        "X00X",
        "X000"};

    vector<vector<int>> path = ratAndMice(arr);

    return 0;
}

/**
 * Rat and Mice
 *
 * You are given an N*M grid.
 * Each cell (i,j) in the grid is either blocked, or empty.
 * The rat can move from a position towards left, right, up or down on the grid.
 * Initially rat is on the position (1,1).
 * It wants to reach position (N,M) where its mice is waiting for.
 * There exits a unique path in the grid . Find that path and help the rat reach its mice.
 *
 * Input Format
 * Given vector of strings representing a grid with N rows and M columns.
 * 'X' in position (i,j) denotes that the cell is blocked and 'O' denotes that the cell is empty.
 *
 * Output Format
 * Print N lines, containing M integers each.
 * A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and
 * a 0 denotes that the cell is not covered in the path.
 *
 * Sample Input
 * 5 4
 * OXOO
 * OOOX
 * XOXO
 * XOOX
 * XXOO
 * Sample Output
 * 1 0 0 0
 * 1 1 0 0
 * 0 1 0 0
 * 0 1 1 0
 * 0 0 1 1
 * */