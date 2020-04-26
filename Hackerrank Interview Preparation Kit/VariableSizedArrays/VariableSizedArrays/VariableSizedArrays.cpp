// VariableSizedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Refer to problem at -
// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

int ConvertToInt(std::string& line, int i, int j)
{
	double sum = 0;
	double exp = 0;
	while (j >= i)
	{
		int val = line[j] - '0';
		sum += val * pow(10, exp);
		exp++;
		j--;
	}
	return (int)sum;
}

int main()
{
	int numArrays, numQueries;
	std::cin >> numArrays >> numQueries;
	std::cin.ignore();
	
	int** addresses;
	addresses = new int*[numArrays];

	// go through all the input arrays
	for (int i = 0; i < numArrays; i++)
	{
		std::string line;
		std::getline(std::cin, line);
		int j = 0, k = 0, l = 0;

		// while not reached end of input line
		while (line[j] !=  '\0')
		{
			int num = 0;
			// cache initial position of the index
			k = j;

			// progress till either hit a space or end of string
			while (line[j] != ' ' && line[j] != '\0')
			{
				j++;
			}

			// pack the portion between previous space and this space/endl into an integer
			num = ConvertToInt(line, k, j - 1);

			// if this is the first integer then its size of array 
			// else its an element in the array
			if (k == 0)
			{
				addresses[i] = new int[num];
			}
			else 
			{
				addresses[i][l] = num;
				l++;
			}

			// if we're not already at null char then go further
			if (line[j] != '\0') {
				j++;
			}
		}
	}

	// go through all the queries
	for (int i = 0; i < numQueries; i++)
	{
		int j = 0, k = 0;
		std::cin >> j >> k;
		std::cout << addresses[j][k];
		if(i != numQueries - 1)
		{
			std::cout << std::endl;
		}
	}

	// free memory
	for (int i = 0; i < numQueries; i++)
	{
		delete addresses[i];
		addresses[i] = nullptr;
	}
	delete addresses;
	addresses = nullptr;

}
