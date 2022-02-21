#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int calculateTotalMarks(vector<int> v)
{
    int sum = 0;
    for (int marks : v)
    {
        sum += marks;
    }
    return sum;
}

bool compare(pair<string, vector<int>> a, pair<string, vector<int>> b)
{
    return calculateTotalMarks(a.second) > calculateTotalMarks(b.second);
}

int main()
{

    vector<pair<string, vector<int>>> student_marks = {
        {"Rohan", {10, 20, 11}},
        {"Prateek", {10, 21, 3}},
        {"Vivek", {4, 5, 6}},
        {"Rijul", {10, 13, 20}}};

    sort(student_marks.begin(), student_marks.end(), compare);

    for (auto s : student_marks)
    {
        cout << s.first << " " << calculateTotalMarks(s.second) << endl;
    }

    return 0;
}