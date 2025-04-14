// ZigzagConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdexcept> // Add this include for std::exception

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        string output = "";

        for (int i = 0; i < s.length(); i += numRows)
        {
            output += s[i];
        }
        
        for (int i = 0; i < s.length(); i += numRows)
        {
            try 
            {
                output += expandIn(s.substr(i + 1, numRows - 1));
            }
            catch (exception e) 
            {
                cout << "OoB" << endl;
            }
        }

        return output;
    }

    string expandIn(string s)
    {
        string output = ""; 

        if (s.length() > 2) 
        {
            int length = s.length()-2;
            output += s[0];
            output += s[s.length() - 1];
            output += expandIn(s.substr(1, length));
            return output;
        }
        else if (s.length() == 2) 
        {
            output += s[0];
            output += s[1];
            return output;
        }
        else if (s.length() == 1) 
        {
            output += s[0];
            return output;
        }
        else // theoretically shouldn't happen
        {
            return output;
        }
    }
};

int main()
{
    Solution s;

    cout << s.convert("PAYPALISHIRING", 4) << endl;
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
