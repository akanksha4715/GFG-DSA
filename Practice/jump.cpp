#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
int fn(int n,vector<int> arr,int s){
    if(arr[s]==0)
    return 1;
    if(arr[s]<s || arr[s]<=n-s){
        if(arr[s]<s && !visited[s]){
            visited[s]=true;
            return fn(n,arr,s-arr[s]);
        }
        if(arr[s]<=n-s && !visited[s]){
            visited[s]=true;
            return fn(n,arr,s-arr[s]);
        }
    }
    return 0;
}

