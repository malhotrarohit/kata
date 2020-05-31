// Pairs.cpp : Refer to the problem at - https://www.hackerrank.com/challenges/pairs/problem
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Returns true if element l is found within indexes low and high (inclusive) of arr
bool binarySearch(vector<int> arr, int low, int high, int k)
{
    int start = low;
    int end = high;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] < k) start = mid + 1;
        else if (arr[mid] > k) end = mid - 1;
        else return true;
    }

    return false;
}

// Calculate pairs (a,b) in arr s.t. a - b = k s.t. k > 0
int pairs(int k, vector<int> arr) {

    int ans = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (binarySearch(arr, i + 1, arr.size() - 1, arr[i] + k)) ans++;
    }

    return ans;
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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

