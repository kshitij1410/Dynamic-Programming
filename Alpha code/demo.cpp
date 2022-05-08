// aplha code

// anumber like 2314 so you have to find out all the possible word which are form a number eg (b,c,a,d),(w,a,d),(w,14) ,(b,c,14)  -- ans 4
#include <bits/stdc++.h>
using namespace std;

// O(2^n)
int toAlphaCode(vector<int>v, int n)
{

    //base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int option1 = toAlphaCode(v, n - 1);
    if (v[n - 2] * 10 + v[n - 1] <= 26)
    {
        int option2 = toAlphaCode(v, n - 2);

        option1 += option2;
    }
    return option1;
}

// 0(n)
int toAlphaCode1(vector<int>v, int n,int *dp)
{

    //base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if(dp[size]>0){
        return dp[size];
    }

    int option1 = toAlphaCode(v, n - 1);
    if (v[n - 2] * 10 + v[n - 1] <= 26)
    {
        int option2 = toAlphaCode(v, n - 2);

        option1 += option2;
    }
    dp[size]=option1;
    return option1;
}

//O(n)

int toAlphaCode1(vector<int>v, int n)
{

   vector<int>dp(n+1,0);

   dp[0]=1;
   dp[1]=1;

   for(int i=2;i<=n;i++){
    
      dp[i]=dp[i-1];

      if(v[i-2]*10 + v[i-1]<=26){
          dp[i]+=dp[i-2];
      }
   }

   return dp[n];
}
 

int main()
{

    vector<int>v{2,3,1,4};
    // cin>>str;

    int n = v.size();
    cout << toAlphaCode(v, n) << endl;

    return 0;
}