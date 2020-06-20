// Refer to problem at - https://www.hackerrank.com/challenges/luck-balance/problem

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {

    int total_luck = 0;
    vector<int> luck;

    // lose all unimportant contests
    // put all important contests in a sorted set
    for (const vector<int>& contest : contests)
    {
        if (contest[1] == 1)
        {
            luck.push_back(contest[0]);
        }
        else {
            total_luck += contest[0];
        }
    }

    sort(luck.begin(), luck.end(), std::greater<int>());

    // iterate through the sorted set, back to front, from contest with most luck to least
    // if you can lose a contest, lose it, otherwise win it
    for (const int& l : luck)
    {
        if (k > 0)
        {
            total_luck += l;
            k--;
        }
        else {
            total_luck -= l;
        }
    }

    return total_luck;
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

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
