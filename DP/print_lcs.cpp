#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char* printlcs(string s1,string s2,int m,int n){
    int memo[m+1][n+1];
     memset(memo,0,sizeof(memo)+1);
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
    int l= memo[m][n];
    char* lcs=new char[l];
    while(l>0){       
        if(s1[m-1]==s2[n-1]){
            l=l-1;
            lcs[l]=s1[m-1];
            m--;
            n--;       
        }
        else if(memo[m-1][n]>memo[m][n-1]){
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
    string s1,s2;
    int m,n;
   
    getline(cin,s1);
    getline(cin,s2);
    m=s1.length();
    n=s2.length();   
    cout<<printlcs(s1,s2,m,n);

    return 0;
}