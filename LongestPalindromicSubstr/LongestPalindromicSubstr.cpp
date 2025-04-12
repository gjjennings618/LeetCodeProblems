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

        for (int i = 0; i < s.length(); i++)
        {
            palindrome = s[i];
            bool hasLetters = true;
            bool isPalindrome = true;

            int j = 1;

            // Find base string
            string basePalindrome = palindrome;
            int k;
            for (k = i + 1; k < s.length() && isPalindrome; k++)
            {
                basePalindrome += s[k];

                if (!checkIfStringIsPalindrome(basePalindrome))
                {
                    isPalindrome = false;
                }
                else 
                {
                    palindrome = basePalindrome;
                }
            }

            int l = palindrome.length() + i - 1;
            cout << "Base String: " << palindrome << "; Base str.length(): "  << palindrome.length() << endl;
            cout << "i: " << i << "; l: " << l << "; j: " << j << endl;
            isPalindrome = true;

            while (hasLetters && isPalindrome)
            {
                string temp_palindrome = "";
                if ((i - j) >= 0)
                {
                    cout << "Prepend: " << s[i - j] << endl;
                    temp_palindrome += s[i - j];
                }

                temp_palindrome += palindrome;

                if (l + j < s.length())
                {
                    cout << "Append: " << s[l + j] << endl;
                    temp_palindrome += s[l + j];
                }

                cout << "Precheck: " << temp_palindrome << endl;

                isPalindrome = checkIfStringIsPalindrome(temp_palindrome);
                hasLetters = checkIfStringHasRemainingLetters(s.length(), i, j, l);

                if (isPalindrome)
                {
                    palindrome = temp_palindrome;
                }

                cout << temp_palindrome << endl;

                j++;
            }

            cout << "Inner Palindrome: " + palindrome << endl;

            if (palindrome.length() > longest_palindrome.length())
            {
                longest_palindrome = palindrome;
            }
        }

        return longest_palindrome;
    }

    bool checkIfStringHasRemainingLetters(int length, int i, int j, int k)
    {
        return (((i - j) >= 0) || (k + j < length));
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
    std::cout << "SPELL: oifiifssss" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("oifiifssss") << endl << endl;

    std::cout << "SPELL: racecar" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("racecar") << endl << endl;

    std::cout << "SPELL: The eht" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("The eht") << endl << endl;

    std::cout << "SPELL: cbbd" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("cbbd") << endl << endl;

    std::cout << "SPELL: ccc" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("ccc") << endl << endl;

    std::cout << "SPELL: babad" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("babad") << endl << endl;

    std::cout << "SPELL: SQQSYYSQQS" << endl;
    std::cout << "FRISBEE: " + s.longestPalindrome("SQQSYYSQQS") << endl << endl;
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