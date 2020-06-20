// Refer to the problem at - https://www.hackerrank.com/challenges/greedy-florist/problem

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {

    // sort the integers 
    // now if i < j => a[i] <= a[j] therefore |a[i+1] - a[i]| < |a[i+2] - a[i]| & so on for i = {0..n-3}
    sort(arr.begin(), arr.end());

    int minAbsDiff = INT_MAX;

    // just get the min pairwise diff
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int diff = arr[i + 1] - arr[i];
        if (minAbsDiff > diff) minAbsDiff = diff;
    }

    return minAbsDiff;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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
