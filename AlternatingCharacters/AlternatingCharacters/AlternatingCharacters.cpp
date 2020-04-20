// AlternatingCharacters.cpp : Refer to the problem at - https://www.hackerrank.com/challenges/alternating-characters/problem
//

#include <iostream>
#include <string>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    int count = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        cout << result << "\n";
    }

    return 0;
}
