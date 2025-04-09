// LongestSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        string longest_substring = "";
        unordered_map<char, int> char_counter;
        unordered_map<char, int> index_tracker;

        string substr = "";

        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            // If cannot find c in char counter
            if (char_counter.find(c) == char_counter.end()) 
            {
                char_counter.insert(make_pair(c, 0));
                index_tracker.insert(make_pair(c, i));
                substr += c;
                cout << substr << endl;
                if (substr.length() > longest_substring.length())
                {
                    longest_substring = substr;
                }
            }
            else 
            {
                cout << "found duplacate: " << c << endl;

                //reset to first instance
                i = index_tracker[c];
                substr = "";
                index_tracker.clear();
                //reset char_counter
                char_counter.clear();
            }
        }

        return longest_substring.length();
    }
};

int main()
{
    Solution s;

    cout << "Final Output: " << s.lengthOfLongestSubstring("abcabcbb") << endl << endl;
    cout << "Final Output: " << s.lengthOfLongestSubstring("dvdf") << endl << endl;
    cout << "Final Output: " << s.lengthOfLongestSubstring("asdfasfghsfh") << endl << endl;
    cout << "Final Output: " << s.lengthOfLongestSubstring("jyyuytyrew") << endl << endl;
    cout << "Final Output: " << s.lengthOfLongestSubstring("asdasasassasdd") << endl << endl;
    cout << "Final Output: " << s.lengthOfLongestSubstring("asxczwfsadfwessf") << endl << endl;
    cout << "Final Output: " << s.lengthOfLongestSubstring("fsdfsdsdsd") << endl << endl;

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
