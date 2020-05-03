// Refer to the problem at - https://www.hackerrank.com/challenges/special-palindrome-again/problem

#include <iostream>
#include <string>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {

    long int numSpecialStrings = 0;

    // stores the length of the most recent streak of consecutive occurrences of a certain character in the array
    int prevWindowLen[26] = { 0 };

    for (int i = 0; i < n; i++)
    {
        // start with window len = 1
        int currWindowLen = 1;

        // keep moving ahead as long as we are within limits & consecutive characters are of the same value
        while (i < n - 1 && s[i] == s[i + 1])
        {
            currWindowLen++;
            i++;
        }

        // count the # of special strings encountered as part of current window and add any special strings formed in conjunction with previous window
        numSpecialStrings += ((currWindowLen * (currWindowLen + 1) / 2) + (prevWindowLen[s[i] - 'a'] < currWindowLen ? prevWindowLen[s[i] - 'a'] : currWindowLen));

        // if we're within limits and the same character is present 2 places ahead then cache length of the current window for using later
        if (i < n - 2 && s[i] == s[i + 2])
        {
            prevWindowLen[s[i] - 'a'] = currWindowLen;
        }
        else
        {
            prevWindowLen[s[i] - 'a'] = 0;
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
