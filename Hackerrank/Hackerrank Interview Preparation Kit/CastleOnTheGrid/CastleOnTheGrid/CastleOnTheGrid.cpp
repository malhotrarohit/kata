// Refer to the problem at - https://www.hackerrank.com/challenges/castle-on-the-grid/problem

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct point
{
    int X;
    int Y;
    int dist;
};

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {

    queue<point> points;

    // begin customized bfs
    point start;
    start.X = startX;
    start.Y = startY;
    start.dist = 0;
    grid[startX][startY] = 'V';

    // push start node into the queue
    points.push(start);

    // iterate until we have visited all the nodes
    while (!points.empty())
    {
        // pick the first element in the queue as "current node"
        // whose unvisited neighbors shall be visited in this iteration
        point pt = points.front();
        int xcoord = pt.X;
        int ycoord = pt.Y;
        int dist = pt.dist;
        int i = 0;
        int j = 0;

        // if this is the goal node then it's distance from origin is the answer
        if (xcoord == goalX && ycoord == goalY) return dist;

        // visit unvisited nodes to the left
        j = ycoord;
        while (true)
        {
            // if this is the goal node then ans = current node's distance from origin + 1
            if (xcoord == goalX && j == goalY) return dist + 1;
            if (j - 1 < 0 || grid[xcoord][j - 1] == 'X' || grid[xcoord][j - 1] == 'V') break;
            grid[xcoord][j - 1] = 'V';
            j--;

            pt.X = xcoord;
            pt.Y = j;
            pt.dist = dist + 1; // since it's reachable within 1 move from the current node
            points.push(pt);
        }

        // visit unvisited nodes up
        i = xcoord;
        while (true)
        {
            // if this is the goal node then ans = current node's distance from origin + 1
            if (i == goalX && ycoord == goalY) return dist + 1;
            if (i - 1 < 0 || grid[i - 1][ycoord] == 'X' || grid[i - 1][ycoord] == 'V') break;
            grid[i - 1][ycoord] = 'V';
            i--;

            pt.X = i;
            pt.Y = ycoord;
            pt.dist = dist + 1; // since it's reachable within 1 move from the current node
            points.push(pt);
        }

        // visit unvisited nodes to the right
        j = ycoord;
        while (true)
        {
            // if this is the goal node then ans = current node's distance from origin + 1
            if (xcoord == goalX && j == goalY) return dist + 1;
            if (j + 1 >= (int)grid[xcoord].size() || grid[xcoord][j + 1] == 'X' || grid[xcoord][j + 1] == 'V') break;
            grid[xcoord][j + 1] = 'V';
            j++;

            pt.X = xcoord;
            pt.Y = j;
            pt.dist = dist + 1; // since it's reachable within 1 move from the current node
            points.push(pt);
        }

        // visit unvisited nodes down
        i = xcoord;
        while (true)
        {
            // if this is the goal node then ans = current node's distance from origin + 1
            if (i == goalX && ycoord == goalY) return dist + 1;
            if (i + 1 >= (int)grid.size() || grid[i + 1][ycoord] == 'X' || grid[i + 1][ycoord] == 'V') break;
            grid[i + 1][ycoord] = 'V';
            i++;

            pt.X = i;
            pt.Y = ycoord;
            pt.dist = dist + 1; // since it's reachable within 1 move from the current node
            points.push(pt);
        }

        // we're done with this node so remove it from the queue
        points.pop();
    }

    return start.dist;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    cout << result << "\n";

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

