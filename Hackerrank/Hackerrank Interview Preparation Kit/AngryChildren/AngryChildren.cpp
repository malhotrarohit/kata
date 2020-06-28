// Refer to problem at - https://www.hackerrank.com/challenges/angry-children/problem
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {

    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;
    for (int i = 0; i < arr.size() - k + 1; i++)
    {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }
    return minDiff;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    cout << result << "\n";

    return 0;
}
