// CountingInversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Refer to problem - https://www.hackerrank.com/challenges/ctci-merge-sort/problem

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

vector<int> MergeSort(int low, int high, vector<int> arg, long& numInversions)
{
    vector<int> result;
    if (low == high)
    {
        result.push_back(arg[low]);
    }
    else
    {
        int mid = (low + high) / 2;
        vector<int> leftArr = MergeSort(low, mid, arg, numInversions);
        vector<int> rightArr = MergeSort(mid + 1, high, arg, numInversions);
        int i = 0, j = 0;

        while (i < leftArr.size() && j < rightArr.size())
        {
            if (leftArr[i] <= rightArr[j])
            {
                result.push_back(leftArr[i]);
                i++;
            }
            else
            {
                result.push_back(rightArr[j]);
                j++;
                numInversions += leftArr.size() - i;
            }
        }

        while (i < leftArr.size())
        {
            result.push_back(leftArr[i]);
            i++;
        }

        while (j < rightArr.size())
        {
            result.push_back(rightArr[j]);
            j++;
        }
    }

    return result;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {

    long numInversions = 0;
    vector<int> result;
    result = MergeSort(0, arr.size() - 1, arr, numInversions);
    return numInversions;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        long result = countInversions(arr);

        cout << result << "\n";
    }

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

