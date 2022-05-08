
//
// Given a cost matrix cost[][] and a position(m, n) in cost[][], write a function that returns cost of minimum cost path to reach(m, n)
// from(0, 0).Each cell of the matrix represents a cost to traverse through that cell.The total cost of a path to reach(m, n) is the sum of
//  all the costs on that path(including both source and destination).You can only traverse down, right and diagonally lower cells from a
//   given cell, i.e., from a given cell(i, j), cells(i + 1, j), (i, j + 1), and(i + 1, j + 1) can be traversed.You may assume that all costs
//    are positive integers.

#include <bits/stdc++.h>
using namespace std;

//m-row n-col
//takes O(n^2)
int min_cost2(int **input, int m, int n)
{

    int **dp = new int *[m];

    // dp[0]=new int [3];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }

    //store element
    dp[m - 1][n - 1] = input[m - 1][n - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = dp[i + 1][n - 1] + input[i][n - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        dp[m - 1][i] = dp[m - 1][i + 1] + input[m - 1][i];
    }

    //take min of three option
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1])) + input[i][j];
        }
    }

    return dp[0][0];
}

//takes O(3^n)
int min_cost(int **input, int si, int sj, int ei, int ej)
{

    //base case
    if (si == ei && sj == ej)
    {
        return input[ei][ej];
    }

    //outside boundary
    if (si > ei || sj > ej)
    {
        return INT_MAX;
    }
    int option1 = min_cost(input, si, sj + 1, ei, ej);
    int option2 = min_cost(input, si + 1, sj, ei, ej);
    int option3 = min_cost(input, si + 1, sj + 1, ei, ej);

    return input[si][sj] + min(option1, min(option2, option3));
}

int main()
{
    int **input = new int *[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3];

    input[0][0] = 4;
    input[0][1] = 3;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;

    cout << min_cost(input, 0, 0, 2, 2) << endl;
    cout << min_cost2(input, 3, 3);
}