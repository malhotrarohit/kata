// Refer to problem at - https://www.hackerrank.com/challenges/minimum-time-required/problem

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the minTime function below.
unsigned long long minTime(vector<long> machines, long goal) {

    long fastestMachine = LONG_MAX;
    long slowestMachine = LONG_MIN;

    // find the slowest & fastest machine
    for (const long& machine : machines)
    {
        if (fastestMachine > machine)
        {
            fastestMachine = machine;
        }
        if (slowestMachine < machine)
        {
            slowestMachine = machine;
        }
    }

    // the search space for this problem can be described by the function 
    // yield = f(days), such that if day1 < day2 then f(day1) < f(day2)
    // hence the search space is sorted in the # of days
    // compute upper and lower bounds on the search space by assuming all machines are slowest and all machines are fastest respectively
    // and perform binary search within those bounds to determine the min(day) such that goal = yield = f(day) 
    unsigned long long minDays = ceil((goal / machines.size()) * fastestMachine);
    unsigned long long maxDays = ceil((goal / machines.size()) * slowestMachine);
    unsigned long long midDays = 0, yield = 0;

    while (minDays < maxDays)
    {
        midDays = (minDays + maxDays) / 2;

        yield = 0;
        for (const long& machine : machines)
        {
            yield += (midDays / machine);
            if (yield >= goal) break;
        }

        if (yield < goal)
        {
            minDays = midDays + 1;
        }
        else 
        {
            maxDays = midDays;
        }
    }

    return maxDays;
}

int main()
{
    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    unsigned long long ans = minTime(machines, goal);

    cout << ans << "\n";

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
