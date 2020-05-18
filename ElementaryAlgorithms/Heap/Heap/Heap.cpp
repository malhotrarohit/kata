// Heap.cpp : Implementation of a basic max-heap.
//

#include <iostream>
#include <vector>

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

// "Bubbles up" an element at index ind to it's correct position in the heap
void BubbleUp(vector<int>& A, int ind)
{
	if (ind > 0 && ind < A.size())
	{
		int parent = Parent(ind);

		if (parent >= 0)
		{
			if (A[parent] < A[ind])
			{
				Swap(A[parent], A[ind]);
				BubbleUp(A, parent);
			}
		}
	}
}

// Puts a root node in it's correct position in the heap
// assuming it's left and right subtrees are already heaps
void Heapify(vector<int>& A, int ind)
{
	if (ind >= 0 && ind < A.size()) 
	{
		int left = Left(ind);
		int right = Right(ind);
		int max = ind;

		if (left < A.size() && A[max] < A[left])
		{
			max = left;
		}
		if (right < A.size() && A[max] < A[right])
		{
			max = right;
		}

		if (max != ind)
		{
			Swap(A[max], A[ind]);
			Heapify(A, max);
		}
	}
}

// Returns a copy of the element on top of the heap without actually removing it
int PeekMax(vector<int>& A)
{
	if (A.size() > 0)
	{
		return A[0];
	}
	return INT32_MIN;;
}

// Removes the element on top of the heap, returns a copy of it
// rebalances the heap after top extraction
int ExtractMax(vector<int>& A)
{
	int result = A[0];
	Swap(A[0], A[A.size() - 1]);
	A.pop_back();
	Heapify(A, 0);
	return result;
}

// Inserts a number n into the heap
void Insert(vector<int>& A, int n)
{
	A.push_back(n);
	BubbleUp(A, A.size() - 1);
}

// Converts (builds) a vector to a heap
void BuildHeap(vector<int>& A)
{
	int size = A.size();
	int i = size / 2 - 1;
	while (i >= 0)
	{
		Heapify(A, i--);
	}
}

int main()
{
	vector<int> A{ 1, 4, 8, 3, 6, 7, 15, 10, 2, 9 };
	BuildHeap(A);
	cout << "(Peek) Max element in the heap is : " << PeekMax(A) << endl;
	cout << "(Extract) Max element in the heap is : " << ExtractMax(A) << endl;
	cout << "(Extract) Max element in the heap is : " << ExtractMax(A) << endl;
	Insert(A, 20);
	cout << "(Peek) Max element in the heap is : " << PeekMax(A) << endl;
	cout << "(Extract) Max element in the heap is : " << ExtractMax(A) << endl;
	cout << "(Extract) Max element in the heap is : " << ExtractMax(A) << endl;
}