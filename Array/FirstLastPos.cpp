#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarylow(vector<int> nums,int low,int high,int target){
        int minn=INT16_MAX;
        while(low<=high){
            int mid=(high-low)/2 +low;
            if(nums[mid]==target){
                minn=min(mid,minn);
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return minn;
    }
    int binaryhigh(vector<int> nums,int low,int high,int target){
        int minn=INT16_MIN;
        while(low<=high){
            int mid=(high-low)/2 +low;
            if(nums[mid]==target){
                minn=max(mid,minn);
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return minn;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int x,y;
        x=binarylow(nums,0,n-1,target);
        y=binaryhigh(nums,0,n-1,target);
        if(x==INT16_MAX)
            x=-1;
        if(y==INT16_MIN)
            y=-1;
        return {x,y};
    }
};