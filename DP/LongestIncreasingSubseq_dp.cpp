#include<iostream>
#include<algorithm>
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
int longestSubsequence(int n, int a[])
{
 int arr[n];
 for(int i=0;i<n;i++){
     arr[i]=1;
     for(int j=0;j<i;j++){
         if(a[i]>a[j])
         arr[i]=max(arr[i],arr[j]+1);
     }
 }
 return res(arr,n);
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cout<<longestSubsequence(n,a);
return 0;
}