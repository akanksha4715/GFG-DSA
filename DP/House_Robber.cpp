#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        int dp[n],maxx=max(nums[0],nums[1]);
        int curr_max=nums[0];
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            curr_max=max(curr_max,dp[i-2]);
            dp[i]=nums[i]+curr_max;
            maxx=max(maxx,dp[i]);
        }
        return maxx;
    }
};