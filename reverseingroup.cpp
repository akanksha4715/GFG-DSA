#include<bits/stdc++.h>
using namespace std;
vector<long long> reverse(vector<long long> arr,long long n,long long k){
    vector<long long> rev;
    long long x;
    for(long long i=0;i<k;i++){
        x=arr[k-1-i];
        rev.push_back(x);
    }
    for(long long i=k;i<n;i++){
        x=arr[n-k-i];
        rev.push_back(x);
    }
    return rev;
}
int main(){
    long long n,k,x;
    cin>>n;
    
    cin>>k;
    vector<long long> arr;
    for(long long i=0;i<n;i++)
    {cin>>x;
    arr.push_back(x);}
    arr = reverse(arr,n,k);
    for(auto y:arr){
        cout<<y<<" ";
    }
    cout<<endl;
}