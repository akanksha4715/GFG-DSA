#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
//Brute force
int fn(int i,int j,int n){
        if(n==1)
            return -1;
        if(n==j)
            return 0;
        if(j>n)
            return 1001;
        return min(1+fn(i,j+i,n),2+fn(j,j+j,n));
    }
    int minSteps(int n) {
        // unordered_map<string,int> mp;
        return 1+fn(1,1,n);
    }
//Optimized 
int minSteps(int n) {
        vector<int> arr(n+1,INT_MAX);
        arr[0]=arr[1]=0;
        int k;
        for(int i=1;i<n;i++){
            for(int j=2;i*j<=n;j++){
                k=i*j;
                arr[k]=min(arr[k],arr[i]+j);
            }
        }
        return arr[n];
    }
    