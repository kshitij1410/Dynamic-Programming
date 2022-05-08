#include <bits/stdc++.h>
using namespace std;

//count the number of the ways to climb the ladders if you can take atmost k jump

// Recursive Approach O(2^n^k)
int calculateWays(int n, int k)
{

    //base case
    if (n == 0)
        return 1;
        if(n<0){
            return 0;
        }
    

    int output = 0;
    
    for (int i = 1; i <= k; i++)
    {
        output += calculateWays(n - i, k);
    }

    
    return output;
}

// Top Down Approach
//O(n*k)
int calculateWaysTD(int n, int k,int *dp)
{

    //base case
    if (n == 0)
        return 1;
    if(n<0){
     return 0;
    }
    
   if(dp[n]>0){
       return dp[n];
   }
   
    int output = 0;
    
    for (int i = 1; i <= k; i++)
    {
        output += calculateWaysTD(n - i, k,dp);
    }
   
   dp[n]=output;
    
    return output;
}

//Bottom Top Approach
//O(n*k)
int calculateWaysBT(int n, int k)
{
   vector<int >dp(n+1,0);
    dp[0]=1;
    
    for(int i=1;i<=n;i++){
        for(int jump=1;jump<=k;jump++){
             
             if(i-jump>=0){
                 dp[i]+=dp[i-jump];
             }
        }
    }
    return dp[n];
}

//Recurrence Relation 
//O(N+k)

int calculateWaysOPT(int n, int k)
{
   vector<int >dp(n+1,0);
    dp[0]=dp[1]=1;
    
   
   for(int i=2;i<=k;i++){
       dp[i]=2*dp[i-1];
   }

   for(int i=k+1;i<=n;i++){
       dp[i]=2*dp[i-1]-dp[i-k-1];
   }

    return dp[n];
}



int main()
{

    int n;
    cin >> n;
    int k;
    cin >> k;
   
    int dp[100000]={0};
    // cout << calculateWays(n, k);
    cout << calculateWaysTD(n, k,dp);
    

    
    return 0;
}