// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> v = vector<int>();

            if (target > 2) {
                for (int i = 0; i < nums.size(); i++)
                {
                    for (int j = i + 1; j < nums.size(); j++)
                    {
                        if (nums[i] + nums[j] == target)
                        {
                            v.push_back(i);
                            v.push_back(j);
                            return v;
                        }
                    }
                }
            }

            return v;
        }
};

int main()
{
    vector<int> v = vector<int>{};

    for (int i = 0; i < 1000; i++) \
    {
        v.push_back(i);
    }

    vector<int> result1 = twoSum(v, 3);
    vector<int> result2 = twoSum(v, 10);
    vector<int> result3 = twoSum(v, 100);
    vector<int> result4 = twoSum(v, 150);
    vector<int> result5 = twoSum(v, 333);
    vector<int> result6 = twoSum(v, 500);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
