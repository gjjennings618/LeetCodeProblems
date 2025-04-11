#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        string palindrome = "";
        string longest_palindrome = "";

        if (s.length() == 1) 
        {
            return s;
        }

        for (int i = 1; i < s.length(); i++)
        {
            palindrome = tolower(s[i]);
            bool hasLetters = true;
            bool isPalindrome = true;

            int j = 1;
            
            // Two letter unfolding
            if ((i + j) < s.length()) 
            {
                string twoLetterUnfold = palindrome + s[i + j];
                if (checkIfStringIsPalindrome(twoLetterUnfold)) 
                {
                    palindrome = twoLetterUnfold;
                }
            }

            while (hasLetters && isPalindrome)
            {
                string temp_palindrome = "";

                if ((i - j) >= 0)
                {
                    temp_palindrome += tolower(s[i - j]);
                }

                temp_palindrome += palindrome;

                if ((i + j) < s.length())
                {
                    temp_palindrome += tolower(s[i + j]);
                }

                isPalindrome = checkIfStringIsPalindrome(temp_palindrome);
                hasLetters = checkIfStringHasRemainingLetters(s.length(), i, j);

                if (isPalindrome)
                {
                    palindrome = temp_palindrome;
                }

                j++;
            }

            if (palindrome.length() > longest_palindrome.length())
            {
                longest_palindrome = palindrome;
            }
        }

        return longest_palindrome;
    }

    bool checkIfStringHasRemainingLetters(int length, int i, int j)
    {
        return (((i - j) > 0) || (i + j < length));
    }

    bool checkIfStringIsPalindrome(string s)
    {
        int length = s.length();

        for (int i = 0; i <= s.length() / 2; i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.longestPalindrome("oifiifsss") << endl;
    std::cout << s.longestPalindrome("racecar") << endl;
    std::cout << s.longestPalindrome("The eht") << endl;
    std::cout << s.longestPalindrome("cbbd") << endl;
    std::cout << s.longestPalindrome("babad") << endl;
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