#include <bits/stdc++.h>
using namespace std;

int gridPath(int si, int sj, int ei, int ej, int prevI, int prevJ, string **input, int **cost)
{

    //base case
    if (si == ei && sj == ej)
    {
        return cost[si][sj];
    }

    //passable cell
    if (input[si][sj] == ".")
    {
        prevI = si;
        prevJ = sj;
        int option1 = gridPath(si + 1, sj, ei, ej, prevI, prevJ, input, cost);
        int option2 = gridPath(si, sj + 1, ei, ej, prevI, prevJ, input, cost);

        return max(option1, option2);
    }
    else
    {
        //blocked cell

        // case 1:
        if (prevJ == sj && prevI + 1 == si and si<=k)
        {
            int option1 = gridPath(si + 1, sj, ei, ej, prevI, prevJ, input, cost);
            int option2 = gridPath(si, sj + 1, ei, ej, prevI, prevJ, input, cost);

            return max(option1, option2);
        }

        // case 2:
        else
        {
            return -1;
        }
    }
}

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n, k;
        string **input = new string *[n + 1];

        for (int i = 0; i <= n; i++)
        {
            input[i] = new string [n + 1];
        }

        int **cost = new int *[n + 1];

        for (int i = 0; i <= n; i++)
        {
            cost[i] = new int [n + 1];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> input[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> cost[i][j];
            }
        }

        cout << gridPath(1, 1, n, n, 2, 1, input, cost);
    }

    return 0;
}