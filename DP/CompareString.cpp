#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string.h>
using namespace std;
int func(string s1,string s2,int m,int n){
    if(m==0) return n;
    if(n==0) return m;
    if(s1[m-1]==s2[n-1]){
        return func(s1,s2,m-1,n-1);
    }
    else
    {
        return 1+min(func(s1,s2,m-1,n), min(func(s1,s2,m,n-1),func(s1,s2,m-1,n-1)));
    }    
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