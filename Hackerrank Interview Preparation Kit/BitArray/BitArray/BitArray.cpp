// Refer to the problem - https://www.hackerrank.com/challenges/bitset-1/problem
//

#include <iostream>

// Floyd's cycle detection algorithm for an iterative function 
int main()
{
	unsigned int n, s, p, q;
	unsigned int m = 1u << 31;

	std::cin >> n >> s >> p >> q;

	unsigned int hare, tort;
	hare = tort = s % m;
	unsigned int i = 0;

	do {
		tort = (tort * p + q) % m;
		hare = (((hare * p + q) % m) * p + q) % m;
		i++;
	} while (2 * i < n && tort != hare);

	if (tort != hare)
	{
		std::cout << n;
		return 0;
	}
	else 
	{
		unsigned int mu = 0, lambda = 0;
		tort = s % m;
		while (tort != hare)
		{
			hare = (hare * p + q) % m;
			tort = (tort * p + q) % m;
			mu++;
		}
		do
		{
			hare = (hare * p + q) % m;
			lambda++;
		} while (tort != hare);

		std::cout << mu + lambda;
	}
}
