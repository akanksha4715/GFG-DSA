#include<iostream>
#include<cmath>
using namespace std;
int sol(string s,int i,int j){
    if(i==j)
    return 1;

    if(j>i){
    if(s[i]==s[j])
    return 2+sol(s,i+1,j-1);
    else
    {
        return max(sol(s,i+1,j),sol(s,i,j-1));
    }
    }
    else
    {
        return 0;
    }   
}
int main(){
    int n;
    string s;
    getline(cin,s);
    n=s.length()-1;
    cout<<"Min no of deletion req is "<<n+1-sol(s,0,n);
    return 0;
}