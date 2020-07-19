// Refer to the problem at - 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool isPair(const char& c1, const char& c2)
{
    return ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']'));
}
// Complete the isBalanced function below.
string isBalanced(string s) {

    if (s.size() % 2 != 0) return "NO";

    vector<char> stack;
    for (const auto& c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push_back(c);
        }
        else
        {
            if(stack.size() == 0 || !isPair(stack.back(), c)) return "NO";
            else { stack.pop_back(); }
        }
    }
    if (stack.size() != 0) return "NO";

    return "YES";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}
