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
            // capture the substring
            string temp = s.substr(i, j - i + 1);
            // in place sort using sort(), taking addresses of beginning and ending of the string
            sort(temp.begin(), temp.end());
            // increment count in map
            map[temp]++;
        }
    }

    double sum = 0;
    unordered_map<string, double>::iterator it;

    for (it = map.begin(); it != map.end(); it++)
    {
        // calculate nC2 and add
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
