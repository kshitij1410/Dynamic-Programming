#include<bits/stdc++.h>
using namespace std;


int32_t main()
{

  vector<int>wt{1,2,3,5};
  vector<int>val{5,4,8,6};

  int W=5;
  int n=sizeof(wt)/sizeof(wt[0]);

  int **dp;
  dp=new int* [n+1];
  
  for(int i=0;i<=n;i++){

      dp[i]=new int[W+1]; 
  }

   

  // rows
  for(int i=0;i<=W;i++){
      dp[0][i]=0;

  }

// col
for(int i=1;i<=n;i++){
    dp[i][0]=0;
}


  for(int i=1;i<=n;i++){
      for(int j=0;j<=W;j++){

          int inc=0;
          
          //exclude the current number
          dp[i][j]=dp[i-1][j];

          // include
          if(j>=wt[i-1]){
              int index=j-wt[i-1];
              inc= dp[i-1][index] + val[i-1];
          }

          // maximize the price
          dp[i][j]=max(dp[i][j],inc);
      }
  }


  int output=dp[n][W];

  //delete the dynamic array
  delete [] dp;

  cout<<output<<endl;



    return 0;
}