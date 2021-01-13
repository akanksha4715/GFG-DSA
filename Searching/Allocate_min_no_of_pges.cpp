#include<iostream>
using namespace std;
bool possible(int arr[],int fix,int k,int n){
    int sum=0,l=1;
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=fix)
        sum+=arr[i];
        else
        {
            l++;
            sum=arr[i];
        }
        
    }
    return (l<=k);
}
int pages(int arr[],int n,int k){
    int sum=arr[0],maxx=arr[0];
    for(int i=1;i<n;i++){
        sum+=arr[i];
        maxx=max(arr[i],maxx);
    }
    int l=maxx,r=sum,res=sum;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(possible(arr,mid,k,n)){
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        
    }
    return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<pages(a,n,k);
}