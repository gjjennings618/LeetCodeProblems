// IsPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>

using namespace std;
class Solution 
{
public:
    // The bonus challenge is to solve without converting x to a string. The most straightforward method is to make a deque
    bool isPalindrome(int x) 
    {
        // I do not populate deq if the passed int is equal to zero. Zero is a palindrome though
        if (x == 0) return true;

        // Negative numbers cannot be a palindrome as stated by rules
        if (x < 0) return false;

        deque<int> deq;
        
        while (x > 0) 
        {
            int val = x % 10;
            deq.push_front(val);
            x = x / 10;
        }

        int left = 0;
        int right = deq.size() - 1;

        while (left < right) 
        {
            if (deq[left] != deq[right]) 
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};


int main()
{
    Solution s;
    cout << (s.isPalindrome(121) ? "true" : "false") << endl;
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
