// Refer to problem at - https://www.hackerrank.com/challenges/minimum-time-required/problem
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {

    long minDays = LONG_MAX;
    long maxDays = LONG_MIN;
    unordered_map<long, int> unique_machines;

    // build a hash map of # of days taken by any machine to the # of such machines
    // keep track of the slowest machine
    for (const long& machine : machines)
    {
        unique_machines[machine]++;
        if (minDays > machine)
        {
            minDays = machine;
        }
        if (maxDays < machine)
        {
            maxDays = machine;
        }
    }

    unordered_map<long, int>::iterator it;
    long yield = 0;
    long days = 0;

    do
    {
        // reset yield to 0
        yield = 0;

        // increment the total # of days (passed) by the # of days taken by the slowest machine to produce an item
        days += maxDays;

        // calculate factory's total yield when 'days' # of days have passed
        for (it = unique_machines.begin(); it != unique_machines.end(); it++)
        {
            yield += (days / it->first) * it->second;
        }

    } while (yield < goal);

    // if we have come this far it means we have either crossed goal yield or achieved exactly goal yield
    // if we have crossed goal, since the yield increases linearly with the # of days passed, Y = F(days)
    // and we already have a lower bound in the # of days (days  - mx) and an upper bound (days)
    // we can perform binary search within the search space Y[day]
    // to find the exact # of days taken to produce the goal yield
    // search for the exact # of days it takes to produce by performing binary search b/w lower and upper bounds

    // lower bound on the possible # of days it takes to produce the goal yield
    long prevDays = days - maxDays;
    long midDays = 0;

    while (prevDays < days)
    {
        midDays = (prevDays + days) / 2;

        yield = 0;
        for (it = unique_machines.begin(); it != unique_machines.end(); it++)
        {
            yield += (midDays / it->first) * it->second;
        }

        if (yield > goal)
        {
            days = midDays - 1;
        }
        else if (yield < goal)
        {
            prevDays = midDays + 1;
        }
        else
        {
            days = midDays;
        }
    }

    return days;
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

    long ans = minTime(machines, goal);

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