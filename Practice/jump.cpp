#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;

bool fn(int n,vector<int> arr,int s){
    bool x,y;
    if(arr[s]==0)
    return 1;
    if(s<n && s>0){
    if(arr[s]<s || arr[s]<=n-s){
        if(arr[s]<s && !visited[s]){
            visited[s]=true;
            x= fn(n,arr,s-arr[s]);
        }
        if(x==0)
        if(arr[s]<=n-s && !visited[s]){
            visited[s]=true;
             y= fn(n,arr,s-arr[s]);
        }
    }
    }
    return x|y;
    
}
int main(){
    int n,s,x;
    cin>>n;
    vector<int> v;
    
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        visited.push_back(0);
    }
    cin>>s;
    //cout<<visited[0];
    cout<<fn(n,v,s-1);
    return 0;
}
// 7
// 2 1 0 1 2 1 6
// 6