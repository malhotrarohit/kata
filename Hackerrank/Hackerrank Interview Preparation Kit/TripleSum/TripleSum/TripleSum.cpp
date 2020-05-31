// Refer to the problem at - https://www.hackerrank.com/challenges/triple-sum/problem
//

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Find the rightmost insertion point for n in the vector a
int pos(vector<int> a, int n)
{
    int low = 0, high = a.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    
    long sum = 0;
    unordered_set<int>::iterator it;
    unordered_set<int> as, bs, cs;

    // get rid of duplicates in the three given vectors
    for (const int& i : a)
    {
        as.insert(i);
    }
    for (const int& i : b)
    {
        bs.insert(i);
    }
    for (const int& i : c)
    {
        cs.insert(i);
    }

    // add unique elements back to the vectors a and c
    a.clear();
    c.clear();
    for (it = as.begin(); it != as.end(); it++)
    {
        a.push_back(*it);
    }
    for (it = cs.begin(); it != cs.end(); it++)
    {
        c.push_back(*it);
    }

    // sort a and c
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    // find the total # of unique triplets (p,q,r) s.t. p <= q and q >= r
    long pa = 0, pb = 0;
    for (it = bs.begin(); it != bs.end(); it++)
    {
        pa = pos(a, *it);
        pb = pos(c, *it);

        sum += (pa * pb);
    }

    return sum;
}

int main()
{
    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

    cout << ans << "\n";

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
