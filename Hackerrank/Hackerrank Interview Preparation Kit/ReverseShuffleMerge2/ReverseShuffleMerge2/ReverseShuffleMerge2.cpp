// Refer to the problem at - https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    map<char, size_t> present, left;
    auto smallestLeftChar = static_cast<char>('z' + 1);
    auto smallestLeftCharIndex = 0;
    string ans;

    for (const auto& c : s)
    {
        present[c]++;
    }

    for (auto& c : present)
    {
        c.second /= 2;
        left[c.first] = c.second;
    }

    for (int i = s.size() - 1; i >= 0; i --)
    {
        if (present.find(s[i]) != present.end())
        {
            if (s[i] == present.begin()->first)
            {
                ans.push_back(s[i]);

                present[s[i]]--;
                if (present[s[i]] == 0)
                {
                    present.erase(s[i]);
                }

                smallestLeftChar = static_cast<char>('z' + 1);
            }
            else
            {
                if (left[s[i]] > 0)
                {
                    left[s[i]]--;
                    if (s[i] < smallestLeftChar)
                    {
                        smallestLeftChar = s[i];
                        smallestLeftCharIndex = i;
                    }
                }
                else
                {
                    if (s[i] >= smallestLeftChar)
                    {
                        while (i < smallestLeftCharIndex)
                        {
                            i++;
                            left[s[i]]++;
                        }
                        ans.push_back(s[i]);
                        left[s[i]]++;

                        present[s[i]]--;
                        if (present[s[i]] == 0)
                        {
                            present.erase(s[i]);
                        }

                        smallestLeftChar = static_cast<int>('z' + 1);
                    }
                    else 
                    {
                        ans.push_back(s[i]);

                        present[s[i]]--;
                        if (present[s[i]] == 0)
                        {
                            present.erase(s[i]);
                        }

                        smallestLeftChar = static_cast<int>('z' + 1);
                    }
                }
            }
        }
    }

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
