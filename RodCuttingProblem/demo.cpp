#include<bits/stdc++.h>
using namespace std;

int maxProfitTD(int n,vector<int >length,vector<int>price,int*dp)
{
   //base case
   if(n==0){
       return 0;
   }

   if(dp[n]>0){
       return dp[n];
   }

   int res=0;

   //recursive case
   for(int i=0;i<n;i++){
       if(n>=length[i]){

       int option1=price[i]+maxProfitTD(n-length[i],length,price,dp);

       res=max(option1,res);
       dp[n]=res;
       }
   }
return res;

}

int maxProfit(int n,vector<int >length,vector<int>price)
{
   //base case
   if(n==0){
       return 0;
   }
   int res=0;
   //recursive case
   for(int i=0;i<n;i++){
       if(n>=length[i]){

       int option1=price[i]+maxProfit(n-length[i],length,price);

       res=max(option1,res);


       }
   }
return res;

}

int maxProfitBT(int n,vector<int >length,vector<int>price)
{
   vector<int>dp(n+1,0);
   dp[0]=0;

   for(int i=1;i<=n;i++){
      int ans=0;
       for(int j=0;j<i;j++){
           int current_ans=price[j]+dp[i-(j+1)];
           ans=max(ans,current_ans);
       }
       dp[i]=ans;
   }
   return dp[n];
}

int main(){
  int n;
  n=8;
  vector<int>length{1,2,3,4,5,6,7,8};
  vector<int>price{3,5,8,9,10,17,17,20};
int dp[100000]={0};

//    cout<<maxProfitTD(n,length,price,dp)<<endl;
   cout<<maxProfitBT(n,length,price)<<endl;
    return 0;
}