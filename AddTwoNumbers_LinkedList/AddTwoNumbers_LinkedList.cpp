// AddTwoNumbers_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
		{
			addTwoNumbersCarry(l1, l2, 0);
		}

		ListNode* addTwoNumbersCarry(ListNode* l1, ListNode* l2, int carry)
		{
			if (carry == 0) 
			{
				if (l1 == nullptr && l2 == nullptr && carry == 0)
				{
					return nullptr;
				}
				else if (l1 == nullptr)
				{
					return l2;
				}
				else if (l2 == nullptr)
				{
					return l1;
				}
				else
				{
					int val = l1->val + l2->val;
					int nextCarry = val / 10;
					ListNode* result = new ListNode(val % 10 + carry);
					result->next = addTwoNumbersCarry(l1->next, l2->next, nextCarry);
					return result;
				}
			}
			else 
			{
				if (l1 == nullptr && l2 == nullptr)
				{
					ListNode* result = new ListNode(carry);
					return result;
				}
				else if (l1 == nullptr)
				{
					int val = l2->val + carry;
					int nextCarry = val / 10;
					ListNode* result = new ListNode(val % 10);
					result->next = addTwoNumbersCarry( l2->next, nullptr, nextCarry);
					return result;
				}
				else if (l2 == nullptr)
				{
					int val = l1->val + carry;
					int nextCarry = val / 10;
					ListNode* result = new ListNode(val % 10);
					result->next = addTwoNumbersCarry(l1->next, nullptr, nextCarry);
					return result;
				}
				else
				{
					int val = l1->val + l2->val + carry;
					int nextCarry = val / 10;
					ListNode* result = new ListNode(val % 10);
					result->next = addTwoNumbersCarry(l1->next, l2->next, nextCarry);
					return result;
				}
			}
		}
};

int main()
{
    std::cout << "Hello World!\n";
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
