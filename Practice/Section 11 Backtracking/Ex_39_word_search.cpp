#include <bits/stdc++.h>
using namespace std;

bool searchRec(vector<vector<char>> &board, string word, int s, int i, int j, string ans)
{
    // cout << "s: " << s << " i: " << i << " j: " << j << " ans: " << ans << endl;
    // base case
    if (ans == word)
    {
        return true;
    }
    if (ans == "" and j == board[0].size())
    {
        return searchRec(board, word, s, i + 1, 0, ans);
    }
    if (i >= board.size() or j >= board[0].size() or i < 0 or j < 0)
    {
        return false;
    }

    // recursive case
    char c = word[s];
    if (c == board[i][j])
    {
        // look right
        // cout << "Look Right" << endl;
        bool res = searchRec(board, word, s + 1, i, j + 1, ans + c);
        if (res)
            return true;
        // look down
        // cout << "Look Down" << endl;
        res = searchRec(board, word, s + 1, i + 1, j, ans + c);
        if (res)
            return true;
        // look left
        // cout << "Look Left" << endl;
        res = searchRec(board, word, s + 1, i, j - 1, ans + c);
        if (res)
            return true;
    }
    return searchRec(board, word, s, i, j + 1, ans);
}

bool wordSearch(vector<vector<char>> &board, string word)
{
    return searchRec(board, word, 0, 0, 0, "");
}

int main()
{

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "SEE";

    cout << wordSearch(board, word) ? "true" : "false";

    return 0;
}