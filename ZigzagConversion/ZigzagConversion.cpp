// ZigzagConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdexcept> // Add this include for std::exception
#include <unordered_map>

using namespace std;

class Solution {
public:

    string convert(string s, int numRows) 
    {
        string output = "";

        unordered_map<int, string> layers;

        for (int i = 0; i < numRows; i++) 
        {
            string layer;
            layers.insert(make_pair(i, layer));
        }

        int j = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            if (j == numRows) 
            {
                j = 0;
            }

            layers[j] += s[i];
            j++;
        }

        // layer is a <int, string>
        for (auto& layer : layers) 
        {
            // First is key; second is value
            output += layer.second;
        }

        return output;
    }
};

int main()
{
    Solution s;

    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 2) << endl;
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
