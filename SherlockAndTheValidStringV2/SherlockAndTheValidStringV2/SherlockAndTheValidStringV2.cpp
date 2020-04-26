// Refer to the problem at - https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complete the isValid function below.
string isValid(string input) {
    // array to hold frequencies of chars in the input
    int frequency[26];
    // vector to hold all non zero frequencies
    vector<int> freqOfFrequency;

    for (int i = 0; i < 26; i++)
    {
        frequency[i] = 0;
    }
    // compute the frequencies
    for (const char& c : input)
    {
        frequency[c - 'a']++;
    }
    // add non zero frequencies to vector
    for (const int& freq : frequency)
    {
        if (freq != 0) freqOfFrequency.push_back(freq);
    }
    // sort the frequencies
    sort(freqOfFrequency.begin(), freqOfFrequency.end());

    int counter = 0;
    // if all chars have same frequency, string is valid
    if (freqOfFrequency.front() == freqOfFrequency.back()) return "YES";
    // if we can remove one char & all remaining ones will have the same frequency, string is valid
    if (freqOfFrequency.front() == 1 && freqOfFrequency[1] == freqOfFrequency.back()) return "YES";
    // if we can remove one occurence of a char and all remaining chars with have the same frequency, string is valid
    while (counter < freqOfFrequency.size() - 1)
    {
        // if frequency diff b/w any two chars > 1, string is invalid
        if (freqOfFrequency[counter + 1] - freqOfFrequency[counter] > 1)
        {
            return "NO";
        }
        // if just one char has a frequency that is one higher than the rest of chars, string is valid, otherwise it's invalid
        else if (freqOfFrequency[counter + 1] - freqOfFrequency[counter] == 1 && counter < freqOfFrequency.size() - 2)
        {
                return "NO";
        }
        counter++;
    }
    //  if we've come this far then the string is valid
    return "YES";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
