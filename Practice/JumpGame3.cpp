#include<bits/stdc++.h>
using namespace std;
class Solution {
public:int len;
    bool fn(vector<int>& arr,bool vis[],int i){
        if(arr[i]==0)
            return true;
        //left
            if(i-arr[i]>=0 && !vis[i-arr[i]]){
                vis[i-arr[i]]=true;
                if(fn(arr,vis,i-arr[i]))
                    return true;
                else
                   vis[i-arr[i]]=false; 
            }
        //right
            if(i+arr[i]<len && !vis[i+arr[i]]){
                vis[i+arr[i]]=true;
                if(fn(arr,vis,i+arr[i]))
                    return true;
                else
                    vis[i+arr[i]]=false;
            }
            return false;     
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        len=n;
        bool vis[n];
        memset(vis,0,sizeof(vis));
        vis[start]=1;
        return fn(arr,vis,start);
    }
};