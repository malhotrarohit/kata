// Refer to the problem at - https://www.hackerrank.com/challenges/common-child/problem

#include <iostream>
#include <string>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {

    // max possible length of either string is 5000 characters
    short int** lcs;
    short int result;
    short int len = s1.size();

    // allocate memory for storing solutions to subproblems
    lcs = new short int* [len+1];
    for (int i = 0; i < len + 1; i++)
    {
        lcs[i] = new short int[len + 1];
        for (int j = 0; j < len + 1; j++)
        {
            lcs[i][j] = 0;
        }
    }

    // This is basically a LCS problem - https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
    for (int i = 1; i < len + 1; i++)
    {
        for (int j = 1; j < len + 1; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? lcs[i - 1][j] : lcs[i][j - 1];
            }
        }
    }

    result = lcs[len][len];

    for (int i = 0; i < len + 1; i++)
    {
        delete lcs[i];
    }
    delete lcs;

    return result;
}

int main()
{
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    cout << result << "\n";

    return 0;
}
