// CountingInversionsArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

long mergeAndReturnInversionCount(int arr[], int tempArr[], int lowIndex, int midIndex, int highIndex)
{
    int i = lowIndex, j = midIndex, k = lowIndex;
    long inversionCount = 0;

    while (i <= midIndex - 1 && j <= highIndex)
    {
        if (arr[i] <= arr[j])
        {
            tempArr[k++] = arr[i++];
        }
        else 
        {
            tempArr[k++] = arr[j++];
            inversionCount += (midIndex - i);
        }
    }

    while (i <= midIndex - 1)
    {
        tempArr[k++] = arr[i++];
    }
    while (j <= highIndex)
    {
        tempArr[k++] = arr[j++];
    }

    for (int l = lowIndex; l <= highIndex; l++)
    {
        arr[l] = tempArr[l];
    }

    return inversionCount;
}

long mergeSortInternal(int arr[], int tempArr[], int lowIndex, int highIndex)
{
    if(highIndex > lowIndex)
    {
        int midIndex = (lowIndex + highIndex) / 2;
        int leftInversions = mergeSortInternal(arr, tempArr, lowIndex, midIndex);
        int rightInversions = mergeSortInternal(arr, tempArr, midIndex + 1, highIndex);
        int crossInversions = mergeAndReturnInversionCount(arr, tempArr, lowIndex, midIndex + 1, highIndex);
        return leftInversions + rightInversions + crossInversions;
    }
    return 0;
}

long mergeSortAndReturnInversionCount(int arr[], int n)
{
    int* tempArr = new int[n];
    long inversionCount = mergeSortInternal(arr, tempArr, 0, n - 1);
    delete[] tempArr;
    return inversionCount;
}

long countInversions(int arr[], int n) {

    return mergeSortAndReturnInversionCount(arr, n);
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

        int* arr = new int[n];

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr, n);

        cout << result << endl;
        delete[] arr;
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
