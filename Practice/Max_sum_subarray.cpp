#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxn=INT_MIN,maxx=0,curr_max=0,count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<0)
            {
                maxn=max(maxn,arr[i]);
                count++;
            }
            
            curr_max+=arr[i];
            if(curr_max<0){
                curr_max=0;
            }
            maxx=max(maxx,curr_max);
            
            
        }
        if(count==n)
                return maxn;
            else
                return maxx;
            return 0;
    }
};