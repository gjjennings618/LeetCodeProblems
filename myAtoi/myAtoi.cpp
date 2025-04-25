// myAtoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>
#include <deque>

using namespace std;

class Solution 
{
public:
    int myAtoi(string s) 
    {
        if (s == "") return 0;

        int i = 0;
        bool hasLeadingWhitespace = true;

        while (i < s.length() && hasLeadingWhitespace) 
        {
            if (s[i] == ' ') 
            {
                i++;
            }
            else 
            {
                hasLeadingWhitespace = false;
            }
        }

        if (i >= s.length())
        {
            return 0;
        }

        enum class signedness
        {
            positive,
            negative,
        };

        signedness sign;
        if (s[i] == '-')
        {
            sign = signedness::negative;
            i++;
        }
        else if (s[i] == '+') 
        {
            sign = signedness::positive;
            i++;
        }
        else
        {
            sign = signedness::positive;
        }

        if (i >= s.length())
        {
            return 0;
        }

        bool hasLeadingZeroes = true;

        while (i < s.length() && hasLeadingZeroes) 
        {
            if (s[i] == '0') 
            {
                i++;
            }
            else 
            {
                hasLeadingZeroes = false;
            }
        }

        regex pattern("[0-9]");

        if (i >= s.length() || !regex_match(string(1, s[i]), pattern))
        {
            return 0;
        }

        int output = 0;
        bool onlyNumbers = true;
        while (i < s.length() && onlyNumbers) 
        {
            if (!regex_match(string(1, s[i]), pattern)) 
            {
                onlyNumbers = false;
            }
            else 
            {
                int value = s[i] - '0';

                if (output > (INT_MAX - value) / 10)
                {
                    return (sign == signedness::positive) ? INT_MAX : INT_MIN;
                }
                output = output * 10 + value;
                i++;
            }
        }

        return (sign == signedness::positive) ? output : -output;
    }
};

int main()
{
    Solution s;

    std::cout << s.myAtoi("    1") << endl;
    std::cout << s.myAtoi("    -1") << endl;
    std::cout << s.myAtoi("    +1") << endl;
    std::cout << s.myAtoi("1") << endl;
    std::cout << s.myAtoi("123") << endl;
    std::cout << s.myAtoi(" 123") << endl;
    std::cout << s.myAtoi(" -123") << endl;
    std::cout << s.myAtoi(" +123") << endl;
    std::cout << s.myAtoi("  01234") << endl;
    std::cout << s.myAtoi("01234") << endl;
    std::cout << s.myAtoi("-01234") << endl;
    std::cout << s.myAtoi("+01234") << endl;
    std::cout << s.myAtoi(" -0001234") << endl;
    std::cout << s.myAtoi("0000001234") << endl;
    std::cout << s.myAtoi("   0000001234") << endl;
    std::cout << s.myAtoi("   +0000001234") << endl;
    std::cout << s.myAtoi("-0000000000000") << endl;
    std::cout << s.myAtoi("0000000000000") << endl;
    std::cout << s.myAtoi("         0000000000000") << endl;
    std::cout << s.myAtoi("   -0000001234") << endl;
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
