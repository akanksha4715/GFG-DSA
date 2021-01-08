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
int sol(string s,int i,int j){
    int res=INT16_MAX;;
    if(palin(s,i,j))
         return 0;
    for (int k = i; k < j; k++)
    {      
         res=min(res,1+sol(s,i,k)+sol(s,k+1,j));
    }
    return res;
    
}
int main(){
    int n;
    string s;
    getline(cin,s);
    n=s.length()-1;
    cout<<sol(s,0,n);
    return 0;
}