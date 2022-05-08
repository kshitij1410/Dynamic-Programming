#include <bits/stdc++.h>
using namespace std;

//top down approach
int MaxNonAdjacentSum(int arr[], int n)
{

    vector<int> dp(n, 0);

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++)
    {
        //pick the current number
        int option1=dp[i-2]+arr[i];

        // leave the current number
        int option2=dp[i-1];

        dp[i]=max(option1,option2);

    }

    return dp[n-1];
}

int main()
{

    int arr[] = {6, 10, 12, 7, 9, 14};
    int n = 6;

    cout << MaxNonAdjacentSum(arr, n) << endl;

    return 0;
}