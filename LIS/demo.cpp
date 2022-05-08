#include <bits/stdc++.h>
using namespace std;


//O(n^2)
int LIS(vector<int> v, int n)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {

        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {

            if (v[i] > v[j])
            {

                if (dp[i] <= dp[j])
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
    }


    return *max_element(dp.begin(),dp.end());
}

int main()
{

    vector<int> v{2,1,3,4,9,7,8};
    int size = v.size();

    cout << LIS(v, size);
    return 0;
}