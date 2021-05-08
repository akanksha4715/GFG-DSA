#include<bits/stdc++.h>
using namespace std;
int trappingWater(int arr[], int n){
        // Code here
        int maxl=arr[0],sum=0,maxr=arr[n-1];
        int right[n],left[n];
        left[0]=maxl;
        right[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            maxl=max(maxl,arr[i]);
            left[i]=maxl;
            maxr=max(maxr,arr[n-i-1]);
            right[n-1-i]=maxr;
        }
        for(int i=0;i<n;i++){
            sum+=min(left[i],right[i])-arr[i];
        }
        return sum;
    }