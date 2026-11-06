#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &matrix)
{
    int row, col;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 1)
            {
                row = i;
                col = j;
            }
        }
    }

    int result = 0;
    result += abs(row - 2);
    result += abs(col - 2);
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<vector<int>> matrix(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << solve(matrix) << "\n";
    return 0;
}