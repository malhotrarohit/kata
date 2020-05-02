// MakingAnagrams.cpp : Refer to the problem at - https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
//


#include <iostream>
#include <string>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    int sum = 0;
    int map[26] = { 0 };

    // compute char frequency for first string
    for (const char& c : a)
    {
        map[c - 'a']++;
    }

    // compute the absolute counts of characters that are either present in 'a' but not in 'b' or in 'b' but not in 'a'
    for (const char& c : b)
    {
        map[c - 'a']--;
    }

    // the sum of such character frequencies is the # of deletions that need to be done to make 'a' and 'b' anagrams of each other
    for (const int& i : map)
    {
        int num = i > 0 ? i : i * -1; 
        sum += num;
    }

    return sum;
}

int main()
{

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
