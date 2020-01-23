// RepeatedString.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Refer to problem - 

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string input;

	cin >> input;
	cin >> n;

	int len = input.length();
	int quotient = n / len;
	int remainder = n % len;
	int numOccurencesInPattern = 0;
	int numOccurencesTotal = 0;

	for (const char c : input)
	{
		if (c == 'a')
		{
			numOccurencesInPattern++;
		}
	}

	numOccurencesTotal += numOccurencesInPattern * quotient;

	for (int i = 0; i < remainder; i++)
	{
		if (input[i] == 'a')
		{
			numOccurencesTotal++;
		}
	}
	cout << numOccurencesTotal;
}
