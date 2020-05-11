// SelectionSort.cpp : Basic selection sort and 'double selection' sort that reduces the # of passes by a factor of two
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

// Selection sort is like performing induction on the length of the sorted array (from the left)
// Base case - for i = 0, the inner loop examines every element relative to the one at 0th position and eventually swaps A[0] with A[min]
// Assuming we're done sorting till index k, the next candidate index would be k+1
// Inner loop would simply swap A[k+1] with the smallest element in the index range [k+1, n-1]
// But since all elements in [0,k] < elements in [k+1, n-1], the swap leaves A[k+1] in its correct position [Proved by induction]
void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        if (i != min)
        {
            Swap(A[i], A[min]);
        }
    }
}

// Same as basic selection sort except for it discovers both the smallest and largest element in the unsorted portion in every single pass
// It swaps the smallest element with A[low] and largest element with A[high] where low and high are the lower & higher index bounds of the unsorted portion of the array
void SelectionSortOptimized(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // first index of the unsorted array is candidate for minimum element
        // last index of unsorted array is candidate for maximum element
        // the size of unsorted array decreases by 2 in every iteration
        int min = i, max = n - i - 1;

        for (int j = i; j < n - i; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            if (A[j] > A[max])
            {
                max = j;
            }
        }
        // put minimum element at the beginning of unsorted array
        if (i != min)
        {
            Swap(A[i], A[min]);
        }
        // if element at index i was the maximum element, it must now be at min because it just got swapped
        if (i != min && i == max)
        {
            max = min;
        }
        // put maximum element at end of unsorted array
        if (n - i - 1 != max)
        {
            Swap(A[n - i - 1], A[max]);
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

int main()
{
    int A[10] = { 1, 10, 8, 15, 6, 7, 3, 4, 2, 9 };
    SelectionSort(A, 10);
    PrintArray(A, 10);

    cout << endl;

    int B[10] = { 1, 10, 8, 15, 6, 7, 3, 4, 2, 9 };
    SelectionSortOptimized(B, 10);
    PrintArray(B, 10);
}
