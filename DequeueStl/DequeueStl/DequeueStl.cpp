#include <iostream>
#include <deque>
#include <vector>

void getMaxIndices(int arr[], int low, int high, std::deque<int>& maxIndices)
{
    maxIndices.clear();
    int max = INT32_MIN;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = low; i <= high; i++)
    {
        if (arr[i] == max)
        {
            maxIndices.push_back(i);
        }
    }
}

void printKMax(int arr[], int n, int k) 
{
    std::deque<int> maxIndices;
    int low = 0;

    while (low + k <= n)
    {
        // we don't know the max for previous window so compute the max here
        if (maxIndices.empty())
        {
            getMaxIndices(arr, low, low + k - 1, maxIndices);
        }
        // we already know the max for previous window so figure out how the shift affects new max
        else 
        {
            if (arr[low + k - 1] == arr[maxIndices.front()])
            {
                maxIndices.push_back(low + k - 1);
            }
            else if (arr[low + k - 1] > arr[maxIndices.front()])
            {
                maxIndices.clear();
                maxIndices.push_front(low + k - 1);
            }
            if (low - 1 == maxIndices.front())
            {
                maxIndices.pop_front();
            }
            if (maxIndices.empty())
            {
                getMaxIndices(arr, low, low + k - 1, maxIndices);
            }
        }
        std::cout << arr[maxIndices.front()] << " ";
        low++;
    }
    std::cout << std::endl;
}

int main() 
{

    int t;
    std::cin >> t;
    while (t > 0) {
        int n, k;
        std::cin >> n >> k;
        int i;
        int* arr = new int[n];
        for (i = 0; i < n; i++)
            std::cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}

