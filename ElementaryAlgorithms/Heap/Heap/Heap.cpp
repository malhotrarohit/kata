// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void BubbleUp(vector<int>& A, int ind)
{
	if (ind > 0 && ind < A.size())
	{
		int parent = Parent(ind);

		if (parent > 0)
		{
			if (A[parent] < A[ind])
			{
				Swap(A[parent], A[ind]);
				BubbleUp(A, parent);
			}
		}
	}
}

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

int PeekMax(vector<int>& A)
{
	if (A.size() > 0)
	{
		return A[0];
	}
	return INT32_MIN;;
}

int ExtractMax(vector<int>& A)
{
	int result = A[0];
	Swap(A[0], A[A.size() - 1]);
	A.pop_back();
	Heapify(A, 0);
	return result;
}

void Insert(vector<int>& A, int n)
{
	A.push_back(n);
	BubbleUp(A, A.size() - 1);
}

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