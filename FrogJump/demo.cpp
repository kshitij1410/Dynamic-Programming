#include <bits/stdc++.h>
using namespace std;

int minPossibleCost(int h[], int n,int *dp)
{

    //base case
    if (n == 1 || n == 0)
    {
        return 0;
    }
     if (n == 2)
    {
        return abs(h[1] - h[0]);
    }

    if(dp[n]>0){
        return dp[n];
    }

   
        //recursive case

        int option1 = minPossibleCost(h, n - 1,dp) + abs(h[n - 2] - h[n-1]);
        int option2 = minPossibleCost(h, n - 2,dp) + abs(h[n - 3] - h[n-1]);

        return  dp[n]= min( option1, option2);

           
   
}

int main()
{

    int arr[] = {10,30,40,20};
    int dp[100000]={0};
    cout << minPossibleCost(arr, 4,dp) << endl;
}