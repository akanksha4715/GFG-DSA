//Count no. of subarray wih given sum
#include<iostream>
#include<unordered_set>
using namespace std;
int subarray(int arr[],int target,int n){
      int sum=0,count=0;
    unordered_set<int> sett;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==target)
        count++;
        if(sett.find(sum-target)!=sett.end()){
            count++;
        }
        sett.insert(sum);
        
    }
    return count;

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