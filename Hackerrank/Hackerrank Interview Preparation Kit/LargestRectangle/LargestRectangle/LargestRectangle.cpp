// Refer to the problem at - https://www.hackerrank.com/challenges/largest-rectangle/problem

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {

    map<int, vector<int>> indices;
    
    // create a hash map of numbers and their respective indices in the array
    for (auto i = 0; i < h.size(); i++)
    {
        indices[h[i]].push_back(i);
    }

    auto ans = 0L;
    // for every number find the area of the largest interval which consists of that element as its smallest element
    // choose the largest of all areas as the answer
    for (auto it = indices.begin(); it != indices.end(); it++)
    {
        auto num = it->first;
        auto indexes = it->second;

        for (auto index : indexes)
        {
            if (h[index] != -1)
            {
                auto left = index;
                auto right = index;
                
                while (left > 0 && h[left - 1] != -1)
                {
                    if (h[left] == num)
                    {
                        h[left] = -1;
                    }
                    left--;
                }

                while (right < h.size() - 1 && h[right + 1] != -1)
                {
                    if (h[right] == num)
                    {
                        h[right] = -1;
                    }
                    right++;
                }

                if (h[left] == num) h[left] = -1;
                if (h[right] == num) h[right] = -1;

                auto area = (right - left + 1) * num;
                if (area > ans) ans = area;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
