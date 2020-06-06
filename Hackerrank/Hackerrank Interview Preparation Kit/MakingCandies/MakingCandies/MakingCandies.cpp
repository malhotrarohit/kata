// MakingCandies.cpp : https://www.hackerrank.com/challenges/making-candies/problem
//

#include <algorithm>
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
long minimumPasses(long long m, long long w, long long p, long long n) {

    long numPasses = 0;
    long long candies = 0;

    while (candies < n)
    {
        numPasses++;
        // calculate candy output based on num of machines and worker available to us atm
        long long output = safeMultiply(m, w);
        // if output has overflown the bounds of a 64 bit uint then we're done
        if (output == 0)
        {
            return numPasses;
        }
        // update # of candies we have
        candies += output;
        if (candies >= n) return numPasses;
        // else devote the candies we have to buying more machines/workers
        // split them between buying machines and workers in such a way that maximizes the output in a single pass
        else 
        {
            long long numResources = candies / p;
            long long remCandies = candies % p;

            candies = remCandies;
            
            if (m > w && m - w >= numResources)
            {
                w += numResources;
            }
            else if (w > m && w - m >= numResources)
            {
                m += numResources;
            }
            else 
            {
                long long split = (w + numResources - m) / 2;
                
                if (m > w)
                {
                    m += split;
                    w += numResources - split;
                }
                else
                {
                    w += split;
                    m += numResources - split;
                }
            }
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

    long result = minimumPasses(m, w, p, n);

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

