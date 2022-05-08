#include <bits/stdc++.h>
using namespace std;

//top down approach
int minCoinChange(int m, int coins[], int size)
{

    // base case
    if (m == 0)
    {
        return 0;
    }

    int res = INT_MAX;

    // recursive case

    for (int i = 0; i < size; i++)
    {
        if (coins[i] <= m)
        {
            int option1 = minCoinChange(m - coins[i], coins, size);

            if (option1 != INT_MAX and option1+1<res)
            {
                res=option1+1;
            }
        }
    }
    return res;
}

// bottom up approach 
int minCoinChange1(int m, int coins[], int size){

    vector<int>dp(m+1,0);

    for(int i=1;i<=m;i++){
        dp[i]=INT_MAX;

        for(int j=0;j<size;j++){
            if(i-v[j]>=0 && dp[i-v[j]]!=INT_MAX ){

                dp[i]=min(dp[i],dp[i-v[j]] +1);

            }
        }
    }

    return dp[m]==INT_MAX? -1 : dp[m];
}

int main()
{

    int m = 15;
    int coins[] = {1, 3, 7, 10};
    int size = 4;
    int  ans=minCoinChange(m,coins,size);
    cout<<(ans==INT_MAX? -1 : ans)<<endl;
    // cout<<ans<<endl;
    cout<<minCoinChange1(m,coins,4)<<endl;
    return 0;
}