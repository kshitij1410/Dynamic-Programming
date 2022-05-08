#include <bits/stdc++.h>
using namespace std;

int MaxProfitByRodCutting(int n,vector<int>l,vector<int>price)
{

   //base case
     if(n==0){
         return price
     }

   //recursive case

   for(int i=0;i<n;i++){

       MaxProfitByRodCutting(n-l[i],l,price);
   }



}

int main()
{

    int n;
    cin>>n;
    vector<int>l{1,2,3,4,5,6,7,8};
    vector<int>price{1,5,8,9,10,17,17,20};

    cout<<MaxProfitByRodCutting(n,l,price)<<endl;
    return 0;
}