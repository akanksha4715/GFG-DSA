#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
bool mycmp(Job a,Job b){
    return a.profit>b.profit;
}
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr,arr+n,mycmp);
    bool done[n];
    int res=0,count=0;
    memset(done,0,n);
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead-1;j>=0;j--){
            if(!done[j]){
                done[j]=true;
                res+=arr[i].profit;
                count++;
                break;
            }
        }
    }
    pair<int,int> p;
    p=make_pair(count,res);
    return p;
} 
int main(){
    int n;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].id;
        cin>>arr[i].dead;
        cin>>arr[i].profit;
    }
    pair<int,int> ans =JobScheduling(arr,n);
    cout<<ans.first<<" "<<ans.second;
}
