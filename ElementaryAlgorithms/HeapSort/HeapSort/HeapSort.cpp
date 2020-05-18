// HeapSort.cpp : Implementation of heap sort using a basic binary heap
//

#include <iostream>
using namespace std;

inline int Parent(int ind)
{
	return (ind - 1) / 2;
}

inline int Left(int ind)
{
	return 2 * ind + 1;
}

inline int Right(int ind)
{
	return 2 * ind + 2;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Puts a root node in it's correct position in the heap
// assuming it's left and right subtrees are already heaps
// n is the size of the heap
void Heapify(int A[], int ind, int n)
{
	if (ind >= 0 && ind < n)
	{
		int left = Left(ind);
		int right = Right(ind);
		int max = ind;

		if (left < n && A[max] < A[left])
		{
			max = left;
		}
		if (right < n && A[max] < A[right])
		{
			max = right;
		}

		if (max != ind)
		{
			Swap(A[max], A[ind]);
			Heapify(A, max, n);
		}
	}
}

// Removes the element on top of the heap, returns a copy of it
// rebalances the heap after top extraction
int ExtractMax(int A[], int n)
{
	int result = A[0];
	Swap(A[0], A[n - 1]);
	Heapify(A, 0, n - 1);
	return result;
}

// Converts (builds) an array to a heap
// n is the size of the array
void BuildHeap(int A[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		Heapify(A, i--, n);
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
	int A[10] = { 1, 4, 8, 3, 6, 7, 15, 10, 2, 9 };

	cout << "Unsorted Array: " << endl;
	PrintArray(A, 10);

	BuildHeap(A, 10);

	for (int i = 0; i < 9; i++)
	{
		ExtractMax(A, 10 - i);
	}

	cout << endl << "Sorted Array: " << endl;
	PrintArray(A, 10);

	return 0;
}
