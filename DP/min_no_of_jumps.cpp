#include<iostream>
#include<cmath>
using namespace std;
int minjumps(int arr[],int n){
    if(n==1) return 0;
    int res=INT_MAX;int sub_res=INT16_MAX;
    for(int i=0;i<n-1;i++){
        if(i+arr[i]>=n-1){
        sub_res=minjumps(arr,i+1);
        if(sub_res!=INT16_MAX)
        res=min(res,sub_res+1);
        }
    }
    return res;
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