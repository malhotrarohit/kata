// Refer to the problem at - https://www.hackerrank.com/challenges/special-palindrome-again/problem

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {

    long int numSpecialStrings = 0;
    vector<int> indexes[26];

    // create an array based "hash map" of [c -> (i,j,k...)] where c is a character and i,j,k are its index positions in the input string
    // such that i < j < k ...
    for (int i = 0; i < n; i++)
    {
        indexes[s[i] - 'a'].push_back(i);
    }

    // go through every characters index positions
    for (int i = 0; i < 26; i++)
    {
        int lenPrevWindow = 0, lenWindow = 0;
        int size = indexes[i].size();

        // if all index positions of the character are consecutive
        if (size > 0 && (indexes[i][size - 1] - indexes[i][0] == size - 1))
        {
            numSpecialStrings += (size * (size + 1)) / 2;
        }
        // if not then process the index positions to find multiple (separated) consecutive windows
        else 
        {
            for (int j = 0; j < size; j++)
            {
                int diff = 0;
                // increase window length by 1
                lenWindow++;

                // if we haven't reached the last index position of the character yet
                // find the difference between current index position and the next one
                if (j + 1 < size)
                {
                    diff = indexes[i][j + 1] - indexes[i][j];
                }

                // if we've reached the last index position of the character or the last index position of current consecutive window
                // calculate the # of special strings we've encountered up until this point
                if (diff == 0 || diff > 1)
                {
                    numSpecialStrings += ((lenWindow * (lenWindow + 1) / 2) + (lenPrevWindow < lenWindow ? lenPrevWindow : lenWindow));
                    lenPrevWindow = (diff == 2 ? lenWindow : 0);
                    lenWindow = 0;
                }
            }
        }
    }

    return numSpecialStrings;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    cout << result << "\n";

    return 0;
}
