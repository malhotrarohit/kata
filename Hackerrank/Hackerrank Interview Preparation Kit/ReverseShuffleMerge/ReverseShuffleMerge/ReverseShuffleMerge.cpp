// Refer to problem at - https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool buildString(vector<vector<int>>& pos, vector<int>& freq, string& ans, int low, int high, int len)
{
    bool isCharLeft = false;
    
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            isCharLeft = true;
            if (pos[i][0] > high || pos[i][pos[i].size() - 1] < low) continue;
            else
            {
                for (int j = pos[i].size() - 1; j >= 0; j--)
                {
                    if (pos[i][j] >= low && pos[i][j] <= high)
                    {
                        freq[i]--;
                        ans.push_back(i + 'a');
                        len--;
                        if (buildString(pos, freq, ans, len - 1, pos[i][j] - 1, len)) return true;
                        else
                        {
                            freq[i]++;
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

    vector<int> freq(26, 0);
    vector<vector<int>> pos(26);
    string ans;
    
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
        pos[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; i++)
    {
        freq[i] /= 2;
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