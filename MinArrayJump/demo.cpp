#include <bits/stdc++.h>
using namespace std;

//O(n^2)
int minArrayJump(vector<int> arr, int n)
{
    int ans = 0;
    for (int i = 0; i < n;)
    {

        int mx = 0;
        int idx = 0;
        int j = i + 1;
        int temp = arr[i];
        while (temp--)
        {

            if (mx < arr[j])
            {
                mx = arr[j];
                idx = j;
            }
            if (j == n - 1)
            {
                idx = n;
                break;
            }
            j++;
        }
        i = idx;
        ans++;
    }
    return ans;
}

//recursive
int minArrayJumpR(vector<int> arr, int n, int idx, vector<int> dp)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    if (n - 1 == idx)
    {
        return 0;
    }
    if (idx >= n)
    {
        return INT_MAX;
    }

    //recursive case
    if (dp[idx] > 0)
    {
        return dp[idx];
    }
    int res = INT_MAX;

    int i = idx;
    for (int j = i + 1; j <= i + arr[i]; j++)
    {
        int current_ans = minArrayJumpR(arr, n, j, dp);
        if(current_ans!=INT_MAX)
        res = min(current_ans+1, res);
    }
    dp[idx] = res;

    return res;
}

int main()
{
    vector<int> arr{3, 4, 2, 1, 2, 3, 7};
    int n = arr.size();
    vector<int> dp(n, 0);
    cout << minArrayJump(arr, n) << endl;
    cout << minArrayJumpR(arr, n, 0, dp) << endl;
    return 0;
}