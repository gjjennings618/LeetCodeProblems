// MedianOfTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;

        double median = 0.0;

        vector<int> sorted;
        int combinedsize = nums1.size() + nums2.size();

        bool isEven = false;
        if (combinedsize % 2 == 0) 
        {
            isEven = true;
        }

        while (i < nums1.size() && j < nums2.size()) 
        {
            if (checkMedianThreshold(sorted, combinedsize, isEven, median)) 
            {
                return median;
            }

            if (nums1[i] < nums2[j]) 
            {
                //std::cout << "Insert: " << nums1[i] << endl;
                sorted.push_back(nums1[i]);
                i++;
            }
            else 
            {
                //std::cout << "Insert: " << nums2[i] << endl;
                sorted.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) 
        {
            if (checkMedianThreshold(sorted, combinedsize, isEven, median))
            {
                //cout << "iloop";
                return median;
            }
            
            sorted.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size())
        {
            //cout << "jloop";
            if (checkMedianThreshold(sorted, combinedsize, isEven, median))
            {
                return median;
            }

            sorted.push_back(nums2[j]);
            j++;
        }

        //cout << endl << ":(" << endl;
        if (checkMedianThreshold(sorted, combinedsize, isEven, median))
        {
            return median;
        }
        else 
        {
            return 0.0;
        }
    }

    bool checkMedianThreshold(vector<int> sorted, int combinedsize, bool isEven, double& median)
    {
        if (sorted.size() >= (combinedsize / 2) + 1) 
        {
            //std::cout << "Past median thresh: " << combinedsize << " " << isEven << " " << median << endl;

            if (isEven)
            {
                median = findAvg(sorted[sorted.size() - 1], sorted[sorted.size() - 2]);
            }
            else
            {
                median = sorted[sorted.size() - 1];
            }

            return true;
        }

        return false;
    } 
    
    double findAvg(int a, int b)
    {
        return ((double) a + b) / 2;
    }
};

int main()
{
    Solution s;
    vector<int> a = { 1};
    vector<int> b = { };
    //vector<int> a = {1, 2, 3, 4, 5, 6};
    //vector<int> b = {-9, 2, 5, 6, 10};
    std::cout << s.findMedianSortedArrays(a, b) << endl;
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
