#include <bits/stdc++.h>
using namespace std;

//recursive solution
//O(2^N)
int uniquePath(int **input, int si, int sj, int ei, int ej)
{

    //base case
    if (si == ei && sj == ej)
    {
        return 1;
    }

    //outside boundary
    if (si > ei || sj > ej)
    {
        return 0;
    }

    //recursive call
    int option1 = uniquePath(input, si, sj + 1, ei, ej);
    int option2 = uniquePath(input, si + 1, sj, ei, ej);

    return option1 + option2;
}

//dp
int uniquePaths(int m, int n)
{
    int **dp = new int *[m];

    for (int i = 1; i <= m; i++)
    {
        dp[i] = new int[n];
    }

    dp[m][n] = 1;

    for (int i = m; i >= 1; i--)
    {
        dp[i][n] = 1;
    }

    for (int i = n; i >= 1; i--)
    {
        dp[m][i] = 1;
    }

    for (int i = m - 1; i >= 1; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    int ans = dp[1][1];
    delete[] dp;
    return ans;
}

int main()
{

    int **input = new int *[3];

    input[1] = new int[2];
    input[2] = new int[2];
    input[3] = new int[2];
    int ans = 0;
    cout << uniquePath(input, 1, 1, 3, 2) << endl;
    cout << uniquePaths(3, 7) << endl;
}