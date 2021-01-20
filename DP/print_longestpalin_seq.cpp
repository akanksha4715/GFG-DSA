#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char* sol(string s,int n){
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
    int l= dp[0][n-1];
    char* lcs=new char[l];
    string s1=s;
    string s2=s1;
    reverse(s2.begin(),s2.end());
    int m=n;
    while(l>0){       
        if(s1[m-1]==s2[n-1]){
            l=l-1;
            lcs[l]=s1[m-1];
            m--;
            n--;       
        }
        else if(dp[m-1][n]>dp[m][n-1]){
            m--;
        }
        else
        {
            n--;
        }
        
    }
    return lcs;
}
int main(){
    int n;
    string s;
    getline(cin,s);
    n=s.length();
    cout<<sol(s,n);
    return 0;
}