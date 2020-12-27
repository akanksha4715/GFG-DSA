#include<iostream>
#include<cmath>
using namespace std;
int res(int arr[],int n){
    int res=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>res)
        res=arr[i];
    }
    return res;
}
int longestSumSubsequence(int n,int a[]){
    int sum[n];
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                sum[i]=max(sum[i],a[i]+sum[j]);
            }
        }
    }
    return res(sum,n);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<longestSumSubsequence(n,a);
    return 0;
}