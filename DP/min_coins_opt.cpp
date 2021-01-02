#include<iostream>
#include<cmath>
using namespace std;
int minCoin(int arr[],int n,int val){
    int dp[val+1];
    dp[0]=0;
    for(int i=1;i<=val;i++){
       dp[i]=INT16_MAX; 
    }
    for(int i=1;i<=val;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<=i){
                int subres=dp[i-arr[j]];
                if(subres!=INT16_MAX){
                    dp[i]=min(subres+1,dp[i]);
                }
            }
        }
    }
    return dp[val];
}
int main(){
    int n;
    int val;
    cin>>val>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<minCoin(arr,n,val);
    return 0;
}