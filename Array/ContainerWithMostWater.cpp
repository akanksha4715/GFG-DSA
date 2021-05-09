#include<bits/stdc++.h>
using namespace std;

    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int maxx=0,summax=0;
        if(n==0)
            return 0;
        while(low<high){
            summax=(high-low)*min(arr[low],arr[high]);
            maxx=max(maxx,summax);
            arr[high]>arr[low] ? low++ : high--;
            
        }
        return maxx;
    }
