// MakingAnagrams.cpp : Refer to the problem at - https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
//


#include <iostream>
#include <string>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    int sum = 0;
    int map[26] = { 0 };

    for (const char& c : a)
    {
        map[c - 'a']++;
    }

    for (const char& c : b)
    {
        map[c - 'a']--;
    }

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
