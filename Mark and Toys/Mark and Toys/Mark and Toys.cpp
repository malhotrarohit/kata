// Mark and Toys.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Refer to problem - https://www.hackerrank.com/challenges/mark-and-toys/problem

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
// Calculate max # of toys mark can purchase
int maximumToys(vector<int> prices, int k) {

    sort(prices.begin(), prices.end());
    int maxToys = 0;

    for (const int price : prices)
    {
        if (price <= k)
        {
            k -= price;
            maxToys++;
        }
        else {
            return maxToys;
        }
    }
    return maxToys;
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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

