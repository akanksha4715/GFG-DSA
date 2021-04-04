//Count presence of subarray wih given sum
#include<iostream>
#include<unordered_map> // no neg
using namespace std;
int subarray(int arr[],int target,int n){
      int sum=0,maxlen=0;
    unordered_map<int,int> sett;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==target)
        maxlen=max(maxlen,i+1);
        if(sett.find(sum-target)!=sett.end()){
            int l=i-sett[sum-target];
            maxlen=max(maxlen,l);
        }
        sett[sum]=i;      
    }
    return maxlen;
}
int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<subarray(arr,target,n);
    return 0;
}