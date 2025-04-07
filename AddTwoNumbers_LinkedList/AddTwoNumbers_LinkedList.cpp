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
			return addTwoNumbersCarry(l1, l2, 0);
		}

		ListNode* addTwoNumbersCarry(ListNode* l1, ListNode* l2, int carry)
		{
			int sum = 0;
			ListNode* l1Next = nullptr;
			ListNode* l2Next = nullptr;

			if (l1 == nullptr && l2 == nullptr) {
				if (carry == 0)
				{
					return nullptr;
				}
				else
				{
					ListNode* result = new ListNode(carry);
					return result;
				}
			}

			if (l1 != nullptr) 
			{
				l1Next = l1->next;
				sum += l1->val;
			} 

			if (l2 != nullptr)
			{
				l2Next = l2->next;
				sum += l2->val;
			}

			sum += carry;
			int nextCarry = sum / 10;
			ListNode* result = new ListNode(sum%10);
			result->next = addTwoNumbersCarry(l1Next, l2Next, nextCarry);
			return result;
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
