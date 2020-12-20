#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minCoins(int arr[],int n,int sum){
    if(sum==0) return 0;
    int res=INT16_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<=sum){
        int sub_res=minCoins(arr,n,sum-arr[i]);
        if(sub_res<INT16_MAX && sub_res+1<res)
        res=sub_res+1;
        }
    }
    return res;
}
int main(){
    int coins[] =  {2,1, 10}; 
    int m = sizeof(coins)/sizeof(coins[0]); 
    int V = 11; 
    cout << "Minimum coins required is "
         << minCoins(coins, m, V); 
    return 0; 
}