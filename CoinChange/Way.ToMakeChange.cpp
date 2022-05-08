#include <bits/stdc++.h>
using namespace std;

int WaysToMakeCoinChange(int *coins, int m, int size)
{

    //base case
    if (m < 0 || size == 0)
    {
        return 0;
    }

    if (m == 0)
    {
        return 1;
    }

    //recursive call

    int option1 = WaysToMakeCoinChange(coins, m - coins[0], size);
    int option2 = WaysToMakeCoinChange(coins + 1, m, size - 1);



    return option1+option2;
}

int WaysToMakeCoinChange1(int *coins, int m, int size)
{

    //base case
    if (m < 0 || size == 0)
    {
        return 0;
    }

    if (m == 0)
    {
        return 1;
    }

    //recursive call

    int option1 = WaysToMakeCoinChange(coins, m - coins[0], size);
    int option2 = WaysToMakeCoinChange(coins + 1, m, size - 1);



    return option1+option2;
} 

int main()
{

    int coins[] = {1,3,5};
    int M = 15;
    cout<<WaysToMakeCoinChange(coins, M, 3);
    return 0;
}