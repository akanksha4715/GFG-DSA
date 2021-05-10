#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int i=1,j=1,k=0;
        int sum=0;
        if(n<3)
            return 0;
        int arr[n+1];
        arr[3]=1;
        arr[2]=0;
        arr[1]=arr[0]=0;
        for(int i=4;i<=n;i++)
            arr[i] = i-2+arr[i-1];
        int diff[n];
        for(int i=1;i<n;i++){
            diff[i]=nums[i]-nums[i-1];
        }
        while(k<n){
            while(j<n && diff[i]==diff[j]){
                j++;
            }
            sum+=arr[j-i+1];
            k=i=j;
        }
        return sum;
    }
};