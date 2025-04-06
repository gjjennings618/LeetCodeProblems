// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
        vector<int> TwoSum(vector<int>& nums, int target)
        {
            vector<int> v = vector<int>();

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

            return v;
            return v;
        }
};

int main()
{
    Solution s;

    vector<int> nums = vector<int>{};

    for (int i = 1; i < 1000; i++) \
    {
        nums.push_back(i);
    }

    vector<int> result1 = s.TwoSum(nums, 3);
    vector<int> result2 = s.TwoSum(nums, 10);
    vector<int> result3 = s.TwoSum(nums, 100);
    vector<int> result4 = s.TwoSum(nums, 150);
    vector<int> result5 = s.TwoSum(nums, 333);
    vector<int> result6 = s.TwoSum(nums, 500);

    std::cout << "result1: " << result1[0] << " "  << result1[1] << std::endl;
    std::cout << "result2: " << result2[0] << " " << result2[1] << std::endl;
    std::cout << "result3: " << result3[0] << " " << result3[1] << std::endl;
    std::cout << "result4: " << result4[0] << " " << result4[1] << std::endl;
    std::cout << "result5: " << result5[0] << " " << result5[1] << std::endl;
    std::cout << "result6: " << result6[0] << " " << result6[1] << std::endl;

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
