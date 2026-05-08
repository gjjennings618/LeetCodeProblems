// IsMatch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Solution 
{
public:

    //Iterate through the string 
    bool isMatch(string s, string p)
    {
        if (s.length() < 1) 
        {
            return false;
        }

        bool asteriskMatch = 0;
        int i = 0, j = 0;
        int matchStart = 0;
        char precedesAsterisk;

        while (i < s.length() && j < p.length()) 
        {
            while (p[j] == '*') 
            {
                
            }
            if (!matchChar(s[i], p[j])) 
            {
                j = 0;
                matchStart++;
                i = matchStart;
            }
            else 
            {
                precedesAsterisk = p[j];
                j++;
            }

            i++;
        }

        if (j < p.length()) 
        {
            return false;
        }

        return true;
    }

    bool matchChar(char c, char p) 
    {
        if (p == '.' || c == p)
        {
            return true;
        }
        
        return false;
    }
};

int main()
{
    Solution s;
}
