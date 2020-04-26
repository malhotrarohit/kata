// Refer to the problem at - https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Complete the isValid function below.
string isValid(string input) {

    // map to hold how many times a particular character frequency (1,2,3 etc.) occurs in the input string
    unordered_map<int, int> frequencyMap;

    // array to hold frequencies of every character in the input string
    int charFrequency[26] = { 0 };
    int small = 0, big = 0;

    // compute character frequencies
    for (const char& sym : input)
    {
        charFrequency[sym - 'a']++;
    }

    // go through every character frequency
    for (const int& frequency : charFrequency)
    {
        // only look at characters with non zero frequencies (i.e. characters that are present in the input string)
        if (frequency != 0) 
        {
            // if empty then just add the frequency to initialize the 'frequency of frequency' map
            if (frequencyMap.size() == 0)
            {
                frequencyMap[frequency]++;
            }
            // if one particular frequency has already been seen before
            else if (frequencyMap.size() == 1)
            {
                // if more of the same frequency is found just increment the frequency's frequency (i.e. count)
                if (frequencyMap.find(frequency) != frequencyMap.end())
                {
                    frequencyMap[frequency]++;
                }
                // if the frequency is 1, add it and take note of this frequency and the one entered before it
                else if (frequency == 1)
                {
                    int key = frequencyMap.begin()->first;

                    frequencyMap[frequency]++;
                    small = frequency;
                    big = key;
                }
                // if the frequency is not 1 and we already have another frequency in the map
                else
                {
                    int key = frequencyMap.begin()->first;

                    // if current frequency is bigger than the frequency already present by a difference of 1, add current frequency to the map & take note of the smaller frequency that was already present in the map
                    if (frequency - key == 1)
                    {
                        frequencyMap[frequency]++;
                        small = key;
                    }
                    // if current frequency is smaller than the frequency already present by a difference of 1 & the bigger frequency has only been seen once before
                    // add the current frequency and take note of it
                    else if (key - frequency == 1 && frequencyMap[key] == 1)
                    {
                        frequencyMap[frequency]++;
                        small = frequency;
                    }
                    // current frequency differs from the one previously added by more than 1 so the input can never be a perfect string
                    else
                    {
                        return "NO";
                    }
                }
            }
            // >=2 frequencies already encountered before current frequency
            else
            {
                // if we have already seen this frequency before & it is not equal to 1
                if (frequency != 1 && frequencyMap.find(frequency) != frequencyMap.end())
                {
                    if (frequency == small || frequency == big)
                    {
                        frequencyMap[frequency]++;
                    }
                    else
                    {
                        return "NO";
                    }
                }
                else
                {
                    return "NO";
                }
            }
        }
    }

    return "YES";
}

int main()
{
    string input;
    getline(cin, input);

    string result = isValid(input);

    cout << result << "\n";

    return 0;
}
