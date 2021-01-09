#include<iostream>
#include<cmath>
using namespace std;
bool palin(string s,int i,int j){
    while(i<=j){
    if(s[i]!=s[j])
    return false;
    else
    {
        ++i;
        --j;
    }  
    }
    return true;
}
int sol(string s,int n){
    int dp[n][n],j;
    if(palin(s,0,n-1))
        return 0;
    for(int i=0;i<n;i++)
    dp[i][i]=0;
    for(int gap=1;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            j=i+gap;
            if(palin(s,i,j))
            dp[i][j]=0;
            else
            {   dp[i][j]=INT16_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                }
                
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
    cout<<sol(s,n);
    return 0;
}