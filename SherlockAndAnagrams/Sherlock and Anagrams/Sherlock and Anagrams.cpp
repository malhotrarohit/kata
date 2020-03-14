// Refer to problem here - 
// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    
    unordered_map<string, double> map;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            string temp = s.substr(i, j - i + 1);
            sort(temp.begin(), temp.end());
            map[temp]++;
        }
    }

    double sum = 0;
    unordered_map<string, double>::iterator it;

    for (it = map.begin(); it != map.end(); it++)
    {
        sum = sum + (it->second * ((it->second - 1.0) / 2.0));
    }

    return sum;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    return 0;
}
