#include <iostream>
#include <string>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    int map[26];

    for (int i = 0; i < 26; i++)
    {
        map[i] = 0;
    }

    for (const char c : s1)
    {
        map[c - 'a']++;
    }

    for (const char c : s2)
    {
        if (map[c - 'a'] != 0)
        {
            return "YES";
        }
    }

    return "NO";

}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    return 0;
}
