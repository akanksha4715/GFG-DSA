#include<iostream>
#include<cmath>
using namespace std;
int minjumps(int arr[],int n){
    int res;
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    dp[i]=INT16_MAX;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]+j>=i)
            dp[i]=min(dp[j]+1,dp[i]);
        }
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    cout<<minjumps(arr,n);
    return 0;
}