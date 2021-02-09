#include<iostream>
#include<cmath>
using namespace std;
//return no of combination to form a certain sum
int sub(int arr[],int n,int sum){
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=sum;i++)
    dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }           
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    int sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sub(arr,n,sum);
    return 0;
}