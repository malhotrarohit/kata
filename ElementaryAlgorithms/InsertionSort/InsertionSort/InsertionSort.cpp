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
    // outer loop sets up the induction hypothesis 
    // inner loop performs the inductive step
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

// TODO
int BinarySearch(int A[], int low, int high, int n)
{
    return n;
}

// TODO
void InsertionSortOptimized(int A[], int n)
{

}

int main()
{
    int A[10] = { 1,10,8,15,6,7,3,4,2,9 };
    InsertionSortBasic(A, 10);
    PrintArray(A, 10);
    //InsertionSortOptimized(A, 10);
}
