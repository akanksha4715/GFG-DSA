#include<bits/stdc++.h>
using namespace std;
class NumArray {
    private: vector<int> sum;
            vector<int> num;
public:
   
    NumArray(vector<int>& nums) {
        num=nums;
        sum.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum.push_back(sum[i-1]+nums[i]);
        }
    }
   
    int sumRange(int left, int right) {
        return sum[right]-sum[left]+num[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */