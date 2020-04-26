// CountingTripletsTwo.cpp : https://www.hackerrank.com/challenges/count-triplets-1/problem
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

    unordered_map<long, int> potentialFirstPosition; // store the potential # of triplets that could have a given element as its first member
    unordered_map<long, int> potentialSecondPosition; // store the potential # of triplets that could have a given element as its second member
    long count = 0; // count of # of triplets

    // loop through the input array once
    for (const int& a : arr)
    {
        // number that could potentially precede this element in a triplet
        long key = a / r;

        // 'a' will be the third member of a triplet if a / r is found in second position map
        // at this point we just add the # of triplet a / r is second member of to count
        if(potentialSecondPosition.find(key) != potentialSecondPosition.end() && a % r == 0)
        {
            count += potentialSecondPosition[key];
        }

        // 'a' will be the second member of a triplet is a / r is found in first position map
        // at this point add the number of triplets originating at a / r to the number of triplets of which 'a' is a second member of
        if (potentialFirstPosition.find(key) != potentialSecondPosition.end() && a % r == 0)
        {
            potentialSecondPosition[a] += potentialFirstPosition[key];
        }

        // 'a' could itself be the first member of a triplet that starts at 'a' 
        // so just add 1 to whatever the first position count of 'a' is
        potentialFirstPosition[a] += 1;
    }

    return count;
}

int main()
{
    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

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
