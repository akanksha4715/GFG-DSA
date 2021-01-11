#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int sol(string s,int n){
   int dp[n][n];
   memset(dp,0,sizeof(dp));
   for(int i=0;i<n;i++)
   dp[i][i]=1;
    for(int gap=1;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j=i+gap;
            if(s[i]==s[j])
            dp[i][j]=2+dp[i+1][j-1];
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }           
        }
    }
    return dp[0][n-1];
}
int main(){
    int n;
    string s;
    getline(cin,s);
    n=s.length();
    cout<<"Min no of deletion req is "<<n-sol(s,n);
    return 0;
}