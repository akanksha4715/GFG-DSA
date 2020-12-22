#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int memo[1000][1000];
int lcs(string s1,string s2,int m,int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
            memo[i][j]=1+memo[i-1][j-1];
            }
            else
            {
                memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
            }
            
        }
    }
    return memo[m][n];
}
int main(){
    string s1,s2;
    int m,n;
    memset(memo,0,sizeof(memo)+1);
    getline(cin,s1);
    getline(cin,s2);
    m=s1.length();
    n=s2.length();
    cout<< lcs(s1,s2,m,n)<<endl;
    return 0;
}