// CountingTriplets.cpp : Refer to the problem at - https://www.hackerrank.com/challenges/count-triplets-1/problem

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    
    long max = INT32_MIN;
    long sum = 0;
    // element to index map
    unordered_map<long long, vector<int>> numPosMap;

    // build the element to index map
    // store max element for pruning the search space later on
    for (int i = 0; i < arr.size(); i++)
    {
        numPosMap[arr[i]].push_back(i);
        
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    unordered_map<long long, vector<int>>::iterator it;

    // go through every unique element in the hash map
    for (it = numPosMap.begin(); it != numPosMap.end(); it++)
    {
        long long firstNum = it->first;
        vector<int> firstPos = it->second;

        int secondIndex = 0;
        int thirdIndex = 0;

        long long secondNum = firstNum * r;

        // if prod > max element in the original list, don't bother searching any further
        if (secondNum <= max)
        {
            long long thirdNum = secondNum * r;

            // if prod > max element in the original list, don't bother searching any further
            if (thirdNum <= max) 
            {    
                // see if we can establish that arr[i], r * arr[i] and r * r * arr[i] are all in the original list
                if (numPosMap.find(secondNum) != numPosMap.end() && numPosMap.find(thirdNum) != numPosMap.end())
                {
                    // list of indices occupied by the second & third terms respectively in the original list
                    vector<int> secondPos = numPosMap[secondNum];
                    vector<int> thirdPos = numPosMap[thirdNum];

                    // go through the index lists of the three elements and see if we can establish 
                    // i < j < k relationship between the indices of arr[i], r * arr[i] and r * r * arr[i]  in the original list
                    for (int i = 0; i < firstPos.size(); i++)
                    {
                        bool reset = false;
                        if (secondPos[secondPos.size() - 1] > firstPos[i]) 
                        {
                            for (int j = secondIndex; j < secondPos.size(); j++)
                            {
                                if (secondPos[j] > firstPos[i])
                                {
                                    if (!reset)
                                    {
                                        secondIndex = j;
                                        reset = true;
                                    }

                                    if (thirdPos[thirdPos.size() - 1] > secondPos[j]) 
                                    {
                                        for (int k = thirdIndex; k < thirdPos.size(); k++)
                                        {
                                            if (thirdPos[k] > secondPos[j])
                                            {
                                                sum += (thirdPos.size() - k);
                                                thirdIndex = k;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return sum;
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

    cout << ans << "\n";

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
