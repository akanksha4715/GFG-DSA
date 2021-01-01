#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string.h>
using namespace std;
int func(string s1,string s2,int m,int n){
   int dp[m+1][n+1];
   dp[0][0]=0;
   for(int i=1;i<=m;i++){
       dp[i][0]=i;
   }
   for(int i=1;i<=n;i++){
       dp[0][i]=i;
   }
   for (int i = 1; i<=m; i++)
   {
       for(int j=1;j<=n;j++){
           if(s1[i-1]==s2[j-1])
           dp[i][j]=dp[i-1][j-1];
           else
           {
               dp[i][j]= 1+ min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
           }           
       }
   }
   return dp[m][n];
}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int m=s1.length();
    int n=s2.length();
    cout<<func(s1,s2,m,m);
    return 0;
}