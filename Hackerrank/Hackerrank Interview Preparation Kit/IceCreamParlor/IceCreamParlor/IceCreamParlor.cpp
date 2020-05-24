// IceCreamParlor.cpp : Refer to the problem at - https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem
//

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {

    unordered_map<int, vector<int>> unique_cost;
    unordered_map<int, vector<int>>::iterator it;

    // store the costs as keys in a hash map with their list of indices as their value
    for (int i = 0; i < cost.size(); i++)
    {
        unique_cost[cost[i]].push_back(i);
    }

    for (int i = 0; i < cost.size(); i++)
    {
        // remaining cost
        int rem = money - cost[i];

        // if an item with same cost as remaining cost exists in the cost array
        if (unique_cost.find(rem) != unique_cost.end())
        {
            // in case remaining cost is same as current cost
            if (rem == cost[i])
            {
                // make sure there's at least two instances of current cost
                if (unique_cost[rem].size() > 1)
                {
                    cout << i + 1 << " " << unique_cost[rem][1] + 1 << endl;
                    break;
                }                
            }
            // simply print if remaining cost is different
            else
            {
                cout << i + 1 << " " << unique_cost[rem][0] + 1 << endl;
                break;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
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

