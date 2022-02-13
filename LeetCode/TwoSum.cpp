#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> index;
    map<int, int> indexMap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto itr = indexMap.find(target-nums[i]);
        if (itr == indexMap.end())
        {
            indexMap.insert({nums[i], i});
        }
        else
        {
            index.push_back(itr->second);
            index.push_back(i);
            break;
        }
    }
    return index;
}

int main()
{

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> index = twoSum(nums, target);

    for (int x : index)
    {
        cout << x << "\t";
    }

    return 0;
}