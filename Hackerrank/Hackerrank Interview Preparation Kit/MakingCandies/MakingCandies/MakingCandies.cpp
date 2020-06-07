// MakingCandies.cpp : https://www.hackerrank.com/challenges/making-candies/problem
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

long long safeMultiply(long long m, long long w)
{
    long long x = m * w;

    if (m != 0 && x / m != w)
    {
        return 0;
    }
    else
    {
        return x;
    }
}

// Complete the minimumPasses function below.
long long minimumPasses(long long m, long long w, long long p, long long n) {

    long long numPasses = 0;
    long long candies = 0;

    while (candies < n)
    {
        long long output = safeMultiply(m, w);
        if (output == 0 || output >= n) return numPasses + 1;

        if (candies < p)
        {
            long long jump = min(ceil((double)(p - candies) / output), ceil((double)(n - candies) / output));
            numPasses += jump;
            candies += (output * jump);
        }
        else
        {
            numPasses++;
            candies += output;
        }

        long long numResources = candies / p;
        long long newCandies = candies % p;
        long long newm = m, neww = w;

        if (m > w && m - w >= numResources)
        {
            neww += numResources;
        }
        else if (w > m && w - m >= numResources)
        {
            newm += numResources;
        }
        else
        {
            long long split = (w + numResources - m) / 2;

            if (m > w)
            {
                newm += split;
                neww += numResources - split;
            }
            else
            {
                neww += split;
                newm += numResources - split;
            }
        }

        long long newOutput = safeMultiply(newm, neww);
        if (newOutput == 0 || newOutput >= n) return numPasses + 1;

        if (ceil((double)(n - newCandies) / newOutput) < ceil((double)(n - candies) / output))
        {
            candies = newCandies;
            m = newm;
            w = neww;
        }
    }

    return numPasses;
}

int main()
{
    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    long long m = stoll(mwpn[0]);

    long long w = stoll(mwpn[1]);

    long long p = stoll(mwpn[2]);

    long long n = stoll(mwpn[3]);

    long long result = minimumPasses(m, w, p, n);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

