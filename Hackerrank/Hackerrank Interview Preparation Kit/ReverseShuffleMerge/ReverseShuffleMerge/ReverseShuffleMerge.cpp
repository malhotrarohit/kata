// Refer to problem at - https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool buildString(map<char, vector<int>>& pos, map<char, int>& freq, string& ans, int low, int high, int len)
{
    bool isCharLeft = false;
    map<char, int>::iterator itFreq;
    
    for (itFreq = freq.begin(); itFreq != freq.end(); itFreq++)
    {
        if (itFreq->second > 0)
        {
            isCharLeft = true;

            if (pos[itFreq->first][0] > high || pos[itFreq->first][pos[itFreq->first].size() - 1] < low) continue;

            else
            {
                for (int j = pos[itFreq->first].size() - 1; j >= 0; j--)
                {
                    if (pos[itFreq->first][j] >= low && pos[itFreq->first][j] <= high)
                    {
                        itFreq->second--;
                        ans.push_back(itFreq->first);
                        len--;

                        if (buildString(pos, freq, ans, len - 1, pos[itFreq->first][j] - 1, len)) return true;

                        else
                        {
                            itFreq->second++;
                            ans.pop_back();
                            len++;
                        };
                    }
                }
            }
        }
    }

    return len == 0 && !isCharLeft;
}

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {

    map<char, int> freq;
    map<char, vector<int>> pos;
    map<char, int>::iterator itFreq;
    string ans;
    
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
        pos[s[i]].push_back(i);
    }

    for (itFreq = freq.begin(); itFreq != freq.end(); itFreq++)
    {
        itFreq->second /= 2;
    }

    buildString(pos, freq, ans, s.size() / 2 - 1, s.size() - 1, s.size() / 2);

    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    cout << result << "\n";

    return 0;
}