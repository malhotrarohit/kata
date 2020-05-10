// InsertionSort.cpp : Basic version and Optimized version (optimized to reduce the number of comparisons, not the swaps)
//

#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void InsertionSortBasic(int A[], int n)
{
    // we're basically doing induction on the size of the array
    // base case A[0] is already sorted
    // outer loop sets up the induction hypothesis, inner loop performs the inductive step
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (A[j] < A[j - 1])
            {
                Swap(A[j], A[j - 1]);
            }
        }
    }
}

void PrintArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << '\t';
    }
}

// Searches for an integer n between indices low & high in a given sorted array A
// If the element is found, returns the index next to the index where the element is found
// If the element is not found, returns the index where the element ought to be inserted in the sorted array
int BinarySearch(int A[], int low, int high, int n)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == n)
        {
            return mid + 1;
        }
        else if (A[mid] < n)
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}

// Insertion sort that is optimized to reduce the # of comparisons
// Performs binary search on the growing sorted arraay to find the index where next element A[i] should be inserted to keep the array sorted
void InsertionSortOptimized(int A[], int n)
{
    // induction on the length of the sorted array
    // base case A[0] is already sorted
    for (int i = 1; i < n; i++)
    {
        int pos = BinarySearch(A, 0, i - 1, A[i]);
        // if the element is not already where it should be
        // swap it with all the elements to its left up until it is either in the correct position or the element right before it is equal to it (helps keep the sort stable)
        if (pos != i)
        {
            for (int j = i; j > pos && A[j] != A[j-1]; j--)
            {
                Swap(A[j], A[j - 1]);
            }
        }
    }
}

int main()
{
    int A[10] = { 1,10,8,15,6,7,3,4,2,9 };
    InsertionSortBasic(A, 10);
    PrintArray(A, 10);
    
    cout << endl;

    int B[10] = { 1,10,8,15,6,7,3,4,2,9 };
    InsertionSortOptimized(B, 10);
    PrintArray(B, 10);
}
