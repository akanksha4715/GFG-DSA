#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
            return 0;
        else if(nums[0]>nums[1]){
            return 0;
        }
        else if(nums[n-1]>nums[n-2])
            return n-1;
        else{
            int low=1,high=n-2;
            while(low<=high){
                if(nums[low]>nums[low-1] && nums[low]>nums[low+1])
                    return low;
                else
                    low++;
                if(nums[high]>nums[high-1] && nums[high]>nums[high+1])
                    return high;
                else
                    high--;
            }
        }
        return 0;
    }
};