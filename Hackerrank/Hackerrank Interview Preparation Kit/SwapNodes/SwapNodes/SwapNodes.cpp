#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

void swapping(vector<vector<int>>& indexes, vector<int>& traversal, const int& index, const int& depth, const int& k)
{
    if ((depth % k == 0) && (indexes[index - 1][0] != -1 || indexes[index - 1][1] != -1))
    {
        int temp = indexes[index - 1][0];
        indexes[index - 1][0] = indexes[index-1][1];
        indexes[index - 1][1] = temp;
    }

    if (indexes[index - 1][0] != -1) swapping(indexes, traversal, indexes[index - 1][0], depth + 1, k);
    traversal.push_back(index);
    if (indexes[index - 1][1] != -1) swapping(indexes, traversal, indexes[index - 1][1], depth + 1, k);
}

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

    vector<vector<int>> results;

    for (const int& q : queries)
    {
        vector<int> result;
        swapping(indexes, result, 1, 1, q);
        results.push_back(result);
    }

    return results;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            cout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                cout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
