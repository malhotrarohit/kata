// BubbleSort.cpp : Optimized for smaller runtimes on arrays that are partially sorted at the front or at the end
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

void BubbleSort(int a[], int n)
{
    int i = 0, swapPos = 0;
    int size = 0;

    // all elements are un-sorted initially
    size = n;

    do
    {
        // start from the beginning of the array in every pass
        // no swaps have happened yet, set last swap position to start of the array
        i = 0;
        swapPos = 0;
        
        // iterate through all elements of the unsorted array, comparing every sequential pair
        while (i < size - 1)
        {
            // swap if a predecessor is larger than its successor
            // cache the position of the last sorted element
            if (a[i] > a[i + 1])
            {
                Swap(a[i], a[i + 1]);
                swapPos = i + 1;
            }
            i++;
        }
        // adjust size of the unsorted array as per position of the last sorted element
        size = swapPos;
    } while (swapPos > 0); // run the algorithm as long as elements are getting swapped
}

void PrintArray(int a[], int n)
{
    int i = 0;

    while (i < n)
    {
        cout << a[i++] << '\t';
    }
}

int main()
{
    int A[10] = { 1,10,8,15,6,7,3,4,2,9 };
    BubbleSort(A, 10);
    PrintArray(A, 10);

}
