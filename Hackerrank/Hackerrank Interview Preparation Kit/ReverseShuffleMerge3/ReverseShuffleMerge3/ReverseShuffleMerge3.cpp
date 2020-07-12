// Refer to the problem at - https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Complete the reverseShuffleMerge function below.
// S = merge(reverse(A), shuffle(A))
// shuffle(A) => permutation of characters of A
// reverse(A) => characters of A in reverse order
// merge(A,B) => interspersing A and B s.t. relative orders of characters in A and B is preserved

string reverseShuffleMerge(string s) {
    unordered_map<char, int> freq;
    unordered_map<char, int> count;
    string ans;

    // compute frequencies of every character in the string S
    for (const auto& c : s)
    {
        freq[c]++;
    }
    // compute frequencies of every character in original string A
    // since |S| = 2 * |A|, freq(c) in S = 2 * count(c) in A for all chars c in A
    for (const auto& p : freq)
    {
        count[p.first] = p.second / 2;
    }

    // characters in A appear in the opposite order of characters in S so we will scan S backwards to generate A
    // choose the smallest possible character at every point during the scan while preserving these invariants 
    // 1. relative order of characters in A should be same as in reverse(S)
    // 2. no required character should be left behind i.e. the string A should be valid given S
    for(int i = s.size() - 1; i >= 0; i--)
    {
        freq[s[i]]--;
        if (count[s[i]] < 1) continue;

        count[s[i]]--;
        while (ans.size() > 0 && ans.back() > s[i] && freq[ans.back()] > count[ans.back()])
        {
            count[ans.back()]++;
            ans.pop_back();
        }
        ans.push_back(s[i]);
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

