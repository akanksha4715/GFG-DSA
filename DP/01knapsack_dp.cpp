#include<iostream>
#include<cmath>
using namespace std;
int knapsack(int wt[],int val[],int n,int w){
   int dp[n+1][w+1];
   for(int i=0;i<n+1;i++)
   dp[i][0]=0;
   for(int i=0;i<w+1;i++)
   dp[0][i]=0;
   for(int i=1;i<n+1;i++){
       for(int j=1;j<w+1;j++){
           if(wt[i-1]>j)
           dp[i][j]=dp[i-1][j];
           else
           {
               dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
           }
           
       }
   }
    return dp[n][w];
}
int main(){
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    for(int i=0;i<n;i++)
    cin>>val[i];
    cout<<knapsack(wt,val,n,w);
    return 0;
}