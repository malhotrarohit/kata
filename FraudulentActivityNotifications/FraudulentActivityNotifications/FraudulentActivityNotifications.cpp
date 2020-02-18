// Refer to problem - https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> split_string(string);

int countActivityNotifications(vector<int> expenditure, int d) 
{
    int countNotifications = 0;
    int range = 200;
    int count_expenditure[201];

    if (expenditure.size() > d)
    {
        int start = 0;
        int end = d;

        for (int i = 0; i <= range; i++)
        {
            count_expenditure[i] = 0;
        }

        for (int i = 0; i < d; i++)
        {
            count_expenditure[expenditure[i]]++;
        }

        while (end < expenditure.size())
        {
            if (start > 0 && end > d)
            {
                count_expenditure[expenditure[start - 1]]--;
                count_expenditure[expenditure[end - 1]]++;
            }

            int sum = 0;
            double median = 0.0;
            
            for (int i = 0; i <= range; i++)
            {
                sum += count_expenditure[i];
                
                if (d % 2 != 0)
                {
                    if (sum > d / 2)
                    {
                        median = i;
                        break;
                    }
                }
                else
                {
                    if (sum == d / 2)
                    {
                        median += i;
                    }
                    else if (sum > d / 2)
                    {
                        if (median > 0)
                        {
                            median = (median + i) / 2;
                        }
                        else
                        {
                            median = i;
                        }
                        break;
                    }
                }
            }

            if (expenditure[end] >= 2 * median)
            {
                countNotifications++;
            }

            start++, end++;
        }
    }
    return countNotifications;
}

int main()
{
    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = countActivityNotifications(expenditure, d);

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
