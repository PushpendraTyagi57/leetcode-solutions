#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A, B;
int rowSize, colSize;
int cost;
vector<vector<vector<int>>> dp;
int solve(int i, int j, int gridNumber)
{
    if (i == rowSize - 1 && j == colSize - 1)
        return (gridNumber == 0) ? A[i][j] : B[i][j];
    if (dp[i][j][gridNumber] != -1)
        return dp[i][j][gridNumber];
    int curr = (gridNumber == 0) ? A[i][j] : B[i][j];
    int right = 0, down = 0;
    if (j + 1 < colSize)
    {
        if (gridNumber == 0)
            right = max(curr + solve(i, j + 1, 0), curr - cost + solve(i, j + 1, 1));
        else
            right = max(curr - cost + solve(i, j + 1, 0), curr + solve(i, j + 1, 1));
    }
    if (i + 1 < rowSize)
    {
        if (gridNumber == 0)
            down = max(curr + solve(i + 1, j, 0), curr - cost + solve(i + 1, j, 1));
        else
            down = max(curr - cost + solve(i + 1, j, 0), curr + solve(i + 1, j, 1));
    }
    return dp[i][j][gridNumber] = max(right, down);
}

int maxPathWithSwitch(int M, int N, int S, vector<vector<int>> gridA, vector<vector<int>> gridB)
{
    A = gridA, B = gridB;
    rowSize = M, colSize = N;
    cost = S;
    dp.resize(rowSize, vector<vector<int>>(colSize, vector<int>(2, -1)));
    return max(solve(0, 0, 0), solve(0, 0, 1));
}