#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int memo[100][100];
int scs(string s1,string s2,int m,int n){
    if(memo[m][n]==-1){
        if(m==0 || n==0)
        memo[m][n]=0;
        else{
        if(s1[m-1]==s2[n-1]){
            memo[m][n]=1+scs(s1,s2,m-1,n-1);
        }
        else
        {
            memo[m][n]=max(scs(s1,s2,m-1,n),scs(s1,s2,m,n-1));
        }
        }
        
    }
    return memo[m][n];
}
int main(){
    string s1,s2;
    int m,n;
    memset(memo,-1,sizeof(memo));
    getline(cin,s1);
    getline(cin,s2);
    m=s1.length();
    n=s2.length();
    cout<< m+n-scs(s1,s2,m,n)<<endl;
    return 0;
}