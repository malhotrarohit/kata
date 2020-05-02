// Refer to problem at - https://www.hackerrank.com/challenges/frequency-queries/problem

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {

    unordered_map<int, int> frequencyMap;
    int** frequencyCountMap;
    vector<int> result;

    frequencyCountMap = new int* [100001];

    for (int i = 0; i < 100001; i++)
    {
        frequencyCountMap[i] = new int[1];
        frequencyCountMap[i][0] = 0;
    }

    for (vector<int> query : queries)
    {
        switch (query[0])
        {
            int prevFrequency, postFrequency;

            case 1:
                prevFrequency = frequencyMap[query[1]]++;
                postFrequency = prevFrequency + 1;
                frequencyCountMap[prevFrequency][0]--;
                frequencyCountMap[postFrequency][0]++;
                break;
            case 2:
                if (frequencyMap.find(query[1]) != frequencyMap.end())
                {
                    prevFrequency = frequencyMap[query[1]]--;
                    postFrequency = prevFrequency - 1;
                    frequencyCountMap[prevFrequency][0]--;
                    frequencyCountMap[postFrequency][0]++;

                    if (postFrequency == 0)
                    {
                        frequencyMap.erase(query[1]);
                    }
                }
                break;
            case 3:
                if (query[1] > 100000)
                {
                    result.push_back(0);
                }
                else if (frequencyCountMap[query[1]][0] > 0)
                {
                    result.push_back(1);
                }
                else
                {
                    result.push_back(0);
                }
                break;
        }
    }

    for (int i = 0; i < 100001; i++)
    {
        delete frequencyCountMap[i];
    }
    delete frequencyCountMap;

    return result;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

