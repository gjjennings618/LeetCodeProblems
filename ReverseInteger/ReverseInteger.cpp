// ReverseInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
           
        vector<int> digit_list;
           
        // Handle negative numbers
        bool is_negative = x < 0;
        x = abs(x);
        int output = 0;

        while (x > 0) 
        {
            digit_list.push_back(x % 10);
            x = x / 10;
        }

        try 
        {
            for (int i = 0; i < digit_list.size(); i++)
            {
                output += digit_list[i] * pow(10, digit_list.size() - 1 - i);
            }
               
            if (output > INT_MAX) {
                return 0;
            }
        }
        catch (exception e) 
        {
            return 0; 
        }

        if (is_negative) 
        {
            return output * -1;
        }
        return output;
    }
};

int main()
{
    Solution solution;
    int number = 123;
    cout << "Reversed: " << solution.reverse(number) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
