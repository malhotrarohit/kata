// Refer to problem at - https://www.hackerrank.com/challenges/ctci-big-o/problem

#include <cmath>
#include <iostream>

using namespace std;

// Complete the primality function below.
string primality(int n) {

    if (n == 1) return "Not prime";
    else if (n == 2 || n == 3) return "Prime";
    else if (n % 2 == 0) return "Not prime";
    else 
    {
        int root = sqrt(n);

        for (int i = 3; i <= root; i = i + 2)
        {
            if (n % i == 0) return "Not prime";
        }
    }
    return "Prime";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        cout << result << "\n";
    }

    return 0;
}
