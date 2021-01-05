#include<iostream>
using namespace std;
int nbst(int n){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<nbst(n);
    return 0;
}